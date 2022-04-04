# 理论篇

Git 一开始就引入了两个概念：**object database** 和 **current directory cache**。Git 所有的功能都是以这两个概念为基础。

## object database

**object database** 是一组**可以按照内容查询(content-addressable)**的对象集合。说白了，就是对象的名字是根据对象的内容命名的，内容不一样，名字一定不一样；反过来，名字不一样，内容一定不一样。读到这里大家可能还是一头雾水，别急，我们继续剖析。如何实现这个所谓的**按照内容查询**呢？Linus 使用了 [SHA1](https://en.wikipedia.org/wiki/SHA-1) 摘要算法。对象的名字就是其内容的 SHA1 摘要值。摘要算法**几乎**可以保证内容不同，摘要值一定不一样。

确定了 object 的命名规则，接下来讨论 object 的结构。object 的结构非常简单，可以分为四部分：

-   **tag**，也叫 type，表示 object 的类型，不能包含空格，最后接一个空格表示结束
-   **size**，使用 ascii 字符数字表示的内容长度
-   `\0`，也就是 ascii 中的 **nul** 字符
-   **对象内容**，字节序列，长度为 size

拼在一起效果如下：

```
<ascii tag without space> + <space> + <ascii decimal size> + <byte\0> + <binary data>
```

以上内容经过 zlib 库的 `inflate()` 压缩后存入文件，就得到一个 object，对**压缩后**的内容计算 SHA1 摘要值，便得到了 object 的文件名。

第一个版本的 Git 只定义了三种 object，分别是 **blob**、**tree** 和 **changeset**。我们一一分解。

#### blob

object 的 tag 取值为 `blob`，binary data 域存储文件的内容。这是最简单的 object。假设我们有一个叫 hello.txt 的文件，内容是 `hello world`。转换成 blob 之后的结构如下 `blob 11\0helloworld`，对应的文件名则是 `ede06c6ad21dd15a253f577717792731a320c404`。

大家要注意，blob 对象只存储了文件的内容和大小，并没有存文件的权限等信息，甚至连文件名都没有存。那这些信息存在哪里呢？答案就是 **tree**。

#### tree

tree 对象的 tag 为 `tree`。tree 对象用来根踪目录。其 binary data 域存储一个列表，列表中每一项可能是一个 blob 对象（对应文件），也可能是一个 tree（对应子目录）。每一项的结构包含四部分：

-   **mode**，权限和类型，接空格表示结束
-   **file name**，对象路径
-   `\0`，也就是 ascii 中的 **nul** 字符
-   **sha1**，对象名

拼在一起结构如下：

```
<mode> + <space> + <file name> + <byte\0> + <sha1>
```

注意，tree 列表会根据 **file name** 排序。

举个列子说明一下。假设我们有如下目录结构：

```
.
├── foo
│   └── bar.txt
└── hello.txt
```

该目录对应的 tree 对象列表内ppw如下：

```
040000  tree    69ccc062670532506442789b4340dea98c73afd8        foo
100644  blob    ede06c6ad21dd15a253f577717792731a320c404        hello.txt
```

有两项内容，一项对应 foo 目录，这也是一个 tree 对象；另一项对应 hello.txt，这是一个 blob。而 foo 对应的 tree 对象的内容为：

```
100644  blob    0974d14c8dadb9ad9833dea721c63384b1448415        bar.txt
```

注意，tree 对象中的每一项是通过 `<mode>` 字段来区分是 tree 还是 blob 的；另一个需要注意的是 tree 对象中的每一项都是连在一起的，我们这里为了方便理解，做了分行处理。

好了，抽象的概念总是不易理解。让我们再回顾一下 tree 和 blob 两个对象。blob 只存储文件的**内容**，而文件名和权限信息需要存储到 tree 对象。tree 对象既可以引用 blob，也可以引用 tree。如此一来，使用 tree 和 blob 两类对象，我们就可以存储**一个目录下所有的文件内容和子目录结构**。

可以这么认为，tree 对象和 blob 对象记录了目录和文件的**当前状态**。

那如何使用 tree 和 blob 来跟踪项目呢？

首先，我们要找出所有**文件**，根据内容生成一组 blob 对象。然后，使用**深度优先遍历**所有子目录，生成对应的 tree 对象。显然，**层次最深**的子目录下肯定都是文件了，这样的子目录对应的 tree 对象只包含了 blob 对象；其他子目录和项目根目录对应的 tree 对象既可能包含 blob 对象，也可能包含 tree 对象。我们通过项目根目录的 tree 对象递归查找到所有的 tree 对象和 blob 对象。

假设我们存储了当前所有的 tree 和 blob 对象。这个时候，我们修改了某个文件。我们再脑补一下上段说的算法。遍历所有**文件**，根据内容生成 blob 对象。大家注意，blob 对象只存储内容，内容不变，就不会产生新的 blob 对象。我们只改了一个文件，所以，只会新增加一个 blob 对象。所以，这个文件所在的文件夹对应的 tree 对象肯定要引用刚才生成的新 blob 对象，所以是一个新 tree 对象。同样的，这个文件所在目录的每一级目录对应的 tree 都需要改变，所以会生成一组新的对象。那显然，项目录的 tree 对象也肯定是新的。

回到之前的例子，目录结构为：

```
.
├── foo
│   └── bar.txt
└── hello.txt
```

虚线左侧是最初的 tree 结构。如果我们 **./foo/bar.txt** 的内容改成 `baz`，则会产生一颗新的 tree 结构。变化的对象使用**双线矩形**标出。大家可以看到，hello.txt 的内容没有变化，所以被两个 tree 对象同时引用。

```
                     .
       +----------+  .  +==========+
       |tree:612ef|  .  |tree:87fd7|
       |    ./    |  .  |    ./    |
       +----------+  .  +==========+
       _____/ \_____  ______/ \____
      /             \/             \
 +----------+   +----------+   +==========+
 |tree:69ccc|   |blob:ede06|   |tree:8e4bb|
 |   foo/   |   |hello.txt |   |   foo/   |
 +----------+   +----------+   +==========+
      |              .              |
 +----------+        .         +==========+
 |blob:0974d|        .         |blob:46e91|
 |  bar.txt |        .         |  bar.txt |
 +----------+        .         +==========+
```

所以，我们可以通过项目**根目录**对应的 **tree 对象**来表示项目代码的**版本**。每一次内容改动都会产生一个**新 tree 对象**，也就是一个**新版本**。如果给定一个 **tree 对象** 以及它引用的所有 **tree 对象** 和 **blob 对象**，我们就能恢复对应的目录结构和文件内容。

可是，这次改动的时间、作者和动机该如何记录呢？为了解决这个问题，Git 引入了第三种对象 **changeset**。

#### changeset

changeset 是早期的叫法，后来统一改成了 **commit** 了，而对应的 tag 为 **commit**。binary data 域就比较简单了，是纯文本：

```
tree 612ef8e50a094025e840ee951bce3036b030b888
parent 5cf777191a2da68ee90b0825162930e0f4a30032
author 涛叔 <hi@taoshu.in> Sat Jun 29 18:20:10 2019
committer 涛叔 <hi@taoshu.in> Sat Jun 29 18:20:10 2019

foo
```

这里的换行是真的换行，不是前文为了理解方便而进行的人为断行。

commit 对象首先通过 **tree 字段**指向一个 **tree 对象**，也就是前文说的一个**版本**。

然后会有零个或多个（一般是一个）所谓的 **parent**。如何理理这里的 parent 的数量呢？

还是从前面的例子说。最开始的版本对应 `tree:612ef`。因为这是第一个版本，我们可以创建一个没有 parent 的 commit，也叫 **root commit**。commit 的 SHA1 摘要值就是我们通常所说的 **Git 版本**。我们修改 `./foo/bar.txt` 之后得到 `tree:87fd7`，再创建 commit 的时候就可以使用 parent 字段引用上一个 commit。如此一来，我们就可以通过最新的 commit 追溯到所有历史的 commit。

commit 的其他部分都很简单，不再赘述。

到此，Git 的基础对象就讲完了。那基础对象讲完了，可以讲 Git 命令了吗？对不起，还不行。因为还有另外一个重要概念不得不讲，那就是所谓的**暂存区 (current directory cache)**。

### current directory cache

**暂存区**到底解决了什么问题呢？

前文讲到，一个 commit 对象对应一个 tree 对象，一个 tree 对象对应多个 tree 对象或者 blob 对象。这些 object 都是根据对象的**内容**命名的。我们修改了某个文件之后，需要对比改动的状态和内容。这就需要查看该文件被修改之前的版本。这需要找到当前 commit 对应的 tree，然后根据被修改文件的**路径**该 tree 做**深度优先搜索**才能找到对应的 blob。如果文件目录的层级很深，每一次 git diff 都会触发大量的磁盘操作，势必拖慢速度。

这个问题的根源是 tree 对象没有存储 blob 对象的**完整路径**，一个 blob 对象的路径信息被分散存储到了不同的 tree 对象中。例如前面提到的 `./foo/bar.txt`，路径 `foo` 被存储到了 `tree:612ef`，文件名 `bar.txt` 则被存储到了 `tree:69ccc` 中。解决的思路也很简单，就是**加缓存**。

暂存区是一个文件，路径为 `.git/index`。Git 使用了 mmap 将文件映射到内存，可以像内存一样操作文件内容。文件的内容是一组所谓的 entry，每个 entry 对应一个 blob 对象，并且存储了 blob 对象的**完整路径**和其他一些状态信息。所有的 entry 是按照 blob 对象的文件路径**升序排列**的。这样，对于给定路径，Git 可以使用**二分查找**快速找到对应的 blob 对象。

所以，暂存区是 working directory 和 object database 纽带。

## 实践篇

现在的 Git 命令确实比较复杂，这是多年迭代的结果。早在 2005 年 4 月 8 号 Linux 提交了 [Git 的第一个版本](https://github.com/git/git/commit/e83c5163316f89bfbde7d9ab23ca2e25604af290)。这个版本只有区区 **1036** 行 c 代码，却实现了【理论篇】全部的内容。因为第一个版本的 object database 目录还不是 `.git`，而且还缺少几个必要的工具，我们接下来使用[这个版本](https://github.com/git/git/commit/839a7a06f35bf8cd563a41d6db97f453ab108129)来演示。这是 2005 年 4 月 19 号提交的一个版本，主要引入了很简单的**同步**与**合并**的脚本。我个人认为具有**里程碑**式的意义。

### install

建议大家自己从源码编译。平台推荐使用 linux 或者 mac。

在 mac 下编译需要对源码做少许改动。一个是在 `cache.h` 中引入 `limits.h` 头文件。再一个是修改 `Makefile` 的 `LIBS` 变量，指定链接 libcrypto 库。如果你使用 homebrew 安装的 openssl，则需要给 `Makefile` 中的 CFLAGS 追加 `-L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include` 参数。

如果是 mac 平台，首先会遇到如下错误：

```
./cache.h:13:10: fatal error: 'openssl/sha.h' file not found
#include <openssl/sha.h>
         ^~~~~~~~~~~~~~~
1 error generated.
make: *** [update-cache.o] Error 1
```

这是因为 Make 在构建的时候找不到 openssl 库。为此我们应该先安装 [openssl@1.1](mailto:openssl@1.1)

然后在 Makefile 的 CFLAGS 中追加：

```
-L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include
```

然后运行 make 会发现产生了更多的错误和警告

```
gcc -g -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -I/usr/local/opt/sqlite/include  -c -o update-cache.o update-cache.c
clang: warning: argument unused during compilation: '-L/usr/local/opt/openssl/lib' [-Wunused-command-line-argument]
update-cache.c:8:8: error: implicitly declaring library function 'memcmp' with type 'int (const void *, const void *, unsigned long)' [-Werror,-Wimplicit-function-declaration]
        cmp = memcmp(name1, name2, len);
              ^
update-cache.c:8:8: note: include the header <string.h> or explicitly provide a declaration for 'memcmp'
update-cache.c:27:47: warning: passing 'unsigned char [0]' to parameter of type 'const char *' converts between pointers to integer types with different sign [-Wpointer-sign]
                int cmp = cache_name_compare(name, namelen, ce->name, ce->namelen);
                                                            ^~~~~~~~
update-cache.c:3:72: note: passing argument to parameter 'name2' here
static int cache_name_compare(const char *name1, int len1, const char *name2, int len2)
                                                                       ^
update-cache.c:41:33: error: implicitly declaring library function 'strlen' with type 'unsigned long (const char *)' [-Werror,-Wimplicit-function-declaration]
        int pos = cache_name_pos(path, strlen(path));
                                       ^
update-cache.c:41:33: note: include the header <string.h> or explicitly provide a declaration for 'strlen'
update-cache.c:46:4: error: implicitly declaring library function 'memmove' with type 'void *(void *, const void *, unsigned long)' [-Werror,-Wimplicit-function-declaration]
                        memmove(active_cache + pos, active_cache + pos + 1, (active_nr - pos - 1) * sizeof(struct cache_entry *));
                        ^
update-cache.c:46:4: note: include the header <string.h> or explicitly provide a declaration for 'memmove'
update-cache.c:48:1: warning: non-void function does not return a value [-Wreturn-type]
}
^
update-cache.c:54:23: warning: passing 'unsigned char [0]' to parameter of type 'const char *' converts between pointers to integer types with different sign [-Wpointer-sign]
        pos = cache_name_pos(ce->name, ce->namelen);
                             ^~~~~~~~
update-cache.c:18:39: note: passing argument to parameter 'name' here
static int cache_name_pos(const char *name, int namelen)
                                      ^
update-cache.c:89:2: error: implicitly declaring library function 'memset' with type 'void *(void *, int, unsigned long)' [-Werror,-Wimplicit-function-declaration]
        memset(&stream, 0, sizeof(stream));
        ^
update-cache.c:89:2: note: include the header <string.h> or explicitly provide a declaration for 'memset'
update-cache.c:140:2: error: implicitly declaring library function 'memcpy' with type 'void *(void *, const void *, unsigned long)' [-Werror,-Wimplicit-function-declaration]
        memcpy(ce->name, path, namelen);
        ^
update-cache.c:140:2: note: include the header <string.h> or explicitly provide a declaration for 'memcpy'
update-cache.c:142:22: error: no member named 'st_ctim' in 'struct stat'
        ce->ctime.nsec = st.st_ctim.tv_nsec;
                         ~~ ^
update-cache.c:144:22: error: no member named 'st_mtim' in 'struct stat'
        ce->mtime.nsec = st.st_mtim.tv_nsec;
                         ~~ ^
3 warnings and 7 errors generated.
make: *** [update-cache.o] Error 1
```

这是因为 clang 默认会输出很多警告信息。不要怕，这些警告不影响功能，可以在 CFLAGS 追加 -Wno-everything 隐藏。然后错误信息如下：

```
gcc -Wno-everything -g -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -I/usr/local/opt/sqlite/include  -c -o update-cache.o update-cache.c
update-cache.c:142:22: error: no member named 'st_ctim' in 'struct stat'
        ce->ctime.nsec = st.st_ctim.tv_nsec;
                         ~~ ^
update-cache.c:144:22: error: no member named 'st_mtim' in 'struct stat'
        ce->mtime.nsec = st.st_mtim.tv_nsec;
                         ~~ ^
2 errors generated.
make: *** [update-cache.o] Error 1
```

这个错误是因为 mac 下没有定义 st\_ctime 相关的结构体。通过 man 2 stat 发现，对应的是 st\_ctimespec 结构体，全部改掉：

```
diff --git a/show-diff.c b/show-diff.c
index b8522886a1..6d00ba2a6f 100644
--- a/show-diff.c
+++ b/show-diff.c
@@ -11,11 +11,11 @@ static int match_stat(struct cache_entry *ce, struct stat *st)
 {
        unsigned int changed = 0;

-       if (ce->mtime.sec  != (unsigned int)st->st_mtim.tv_sec ||
-           ce->mtime.nsec != (unsigned int)st->st_mtim.tv_nsec)
+       if (ce->mtime.sec  != (unsigned int)st->st_mtimespec.tv_sec ||
+           ce->mtime.nsec != (unsigned int)st->st_mtimespec.tv_nsec)
                changed |= MTIME_CHANGED;
-       if (ce->ctime.sec  != (unsigned int)st->st_ctim.tv_sec ||
-           ce->ctime.nsec != (unsigned int)st->st_ctim.tv_nsec)
+       if (ce->ctime.sec  != (unsigned int)st->st_ctimespec.tv_sec ||
+           ce->ctime.nsec != (unsigned int)st->st_ctimespec.tv_nsec)
                changed |= CTIME_CHANGED;
        if (ce->st_uid != (unsigned int)st->st_uid ||
            ce->st_gid != (unsigned int)st->st_gid)
diff --git a/update-cache.c b/update-cache.c
index 5085a5cb53..b774c1c631 100644
--- a/update-cache.c
+++ b/update-cache.c
@@ -138,10 +138,10 @@ static int add_file_to_cache(char *path)
        ce = malloc(size);
        memset(ce, 0, size);
        memcpy(ce->name, path, namelen);
-       ce->ctime.sec = st.st_ctime;
-       ce->ctime.nsec = st.st_ctim.tv_nsec;
-       ce->mtime.sec = st.st_mtime;
-       ce->mtime.nsec = st.st_mtim.tv_nsec;
+       ce->ctime.sec = st.st_ctimespec.tv_sec;
+       ce->ctime.nsec = st.st_ctimespec.tv_nsec;
+       ce->mtime.sec = st.st_mtimespec.tv_sec;
+       ce->mtime.nsec = st.st_mtimespec.tv_nsec;
        ce->st_dev = st.st_dev;
        ce->st_ino = st.st_ino;
        ce->st_mode = st.st_mode;
```

然后就会发如下报错：

```
Undefined symbols for architecture x86_64:
  "_SHA1_Final", referenced from:
      _write_cache in update-cache.o
      _index_fd in update-cache.o
      _write_sha1_file in read-cache.o
      _verify_hdr in read-cache.o
  "_SHA1_Init", referenced from:
      _write_cache in update-cache.o
      _index_fd in update-cache.o
      _write_sha1_file in read-cache.o
      _verify_hdr in read-cache.o
  "_SHA1_Update", referenced from:
      _write_cache in update-cache.o
      _index_fd in update-cache.o
      _write_sha1_file in read-cache.o
      _verify_hdr in read-cache.o
  "_deflate", referenced from:
      _index_fd in update-cache.o
      _write_sha1_file in read-cache.o
  "_deflateBound", referenced from:
      _write_sha1_file in read-cache.o
  "_deflateEnd", referenced from:
      _index_fd in update-cache.o
      _write_sha1_file in read-cache.o
  "_deflateInit_", referenced from:
      _index_fd in update-cache.o
      _write_sha1_file in read-cache.o
  "_inflate", referenced from:
      _read_sha1_file in read-cache.o
  "_inflateEnd", referenced from:
      _read_sha1_file in read-cache.o
  "_inflateInit_", referenced from:
      _read_sha1_file in read-cache.o
ld: symbol(s) not found for architecture x86_64
```

这是因为没有指定链接 libcrypto 和 libz，给 Makefile 中的 LIBS 追加 -lcrypto -lz 即可！

改好后执行 `make && make install`，Git 的初代命令会安装到 `$HOME/bin` 中。`$HOME/bin` 需要自己创建，不然 `make install` 会报错。

初代的命令都很简陋。你甚至都找不到一个叫 git 的命令。但它们却又都很本质，实现了 Git 功能最核心的逻辑。命令列表如下：

```
cat-file        # 查看 object 内容
check-files     # ???
checkout-cache  # 从暂存区读取文件内容到工作区
commit-tree     # 提交 commit
diff-tree       # 比较两个 tree 对象的差异
fsck-cache      # ???
init-db         # 初始化 object database
ls-tree         # 查看 tree 对象内容
merge-base      # 查找两个 commit 的最新共公 commit
merge-cache     # 合并
read-tree       # 把 objce database 的一个 tree 对象加载到暂存区
rev-tree        # ???
show-diff       # 比较工作区和暂存区的差异
show-files      # 查看暂存区文件列表
update-cache    # 将工作区文件写入暂存区
write-tree      # 将暂存区的文件列表写入 object database，也就是生成 tree 对象
```

标问号的命令没有用到，也就没仔细看。大家有兴趣可以自行阅读源码。

### init

init-db 是 `git init` 的祖先。init-db 做的事情也很简单，创建 `.git/objects` 目录，然后在 `.git/objects` 下创建从 `00` 到 `ff` 共 256 子目录，效果如下：

```
.git/objects
├── 00
├── 01
├── ...
├── fe
└── ff
```

假设有一个对象的名字是 `00fd73eea32c97c962df8a84ea16c8ae34d4f3bc`，那么存储该对象的文件路径为 `.git/object/00/fd73eea32c97c962df8a84ea16c8ae34d4f3bc`。

### commit

然后大家就可以创建自己的文件。不妨 `echo -n "hello world" > hello.txt`。

为了使用 Git 管理这个 hello.txt，需要依次执行下列操作：

```
# 加入暂存区
➜  update-cache --add hello.text
# 生成 tree 对象并保存到 object database
# $tree 的值为 bf8e48a87fd9fb97b448e3e91a49607472f0c8de
➜  tree=$(write-tree)
# 首次提交
➜  echo init | commit-tree $tree
Committing initial tree bf8e48a87fd9fb97b448e3e91a49607472f0c8de
d7c0b275523e1222a63bb899d2f2cd4b616150ee
➜  echo d7c0b275523e1222a63bb899d2f2cd4b616150ee > .git/HEAD
```

为了引用方便，早期 Git 推荐把最新的 commit 写到 `.git/HEAD` 文件。这时的 Git 还没有 branch 的概念。

查看 commit 内容：

```
➜  cat-file commit $(cat .git/HEAD)
tree bf9e48a87fd9fb97b448e3e91a49607472f0c8de
author 涛叔 <hi@taoshu.in> 1561827318 +0800
committer 涛叔 <hi@taoshu.in> 1561827318 +0800

init
```

这个 cat-file 命可以解析各种 object 的对象，但因为 tree 包含二进制内容，有时还需要递归解析，所以有专门的 ls-tree 命令。

查看 tree 内容：

```
➜ ls-tree bf8e48a87fd9fb97b448e3e91a49607472f0c8de
100644  blob    ede06c6ad21dd15a253f577717792731a320c404        hello.txt
```

查看 blob 内容：

```
➜  cat-file blob ede06c6ad21dd15a253f577717792731a320c404
hello world
```

### reset

如果我们把 hello.txt 删除，我们就可以根据提交内容恢复，操作如下：

```
# 查询最新 commit 对应的 tree
➜  tree=$(cat-file commit $(cat .git/HEAD)|sed 's/tree //;q')
# 将 tree 加载到暂存区
➜  read-tree $tree
# 从暂存区恢复 hello.txt 文件
➜  checkout-cache hello.txt
```

### merge

分支合并是 Git 的灵魂。可 Git 引入合并功能的时候还没有分支这个概念。当时 Git 使用 `read-tree` 进行合并，是以 tree 为单位进行操作的。第一个版本无法处理合并冲突。我们演示的版本的是支持的。

首先，我们先生成两个不同的 tree。

```
# 记录当前 tree 方便合并
➜  cat-file commit $(cat .git/HEAD)|sed 's/tree //;q' > .git/a
# 添加一行，内容为 b
➜  echo -e "\nb" > hello.txt
# 更新暂存区
➜  update-cache --add hello.txt
# 生成 tree 对象并保存到 object database
➜  write-tree > .git/b
# 恢复暂存区到最初版本
➜  read-tree $(cat .git/a)
# 恢复 hello.text 内容
➜  checkout-cache -f hello.txt
# 添加一行，内容为 c
➜  echo -e "\nc" > hello.txt
# 更新暂存区
➜  update-cache --add hello.txt
# 生成 tree 对象并保存到 object database
➜  write-tree > .git/c
```

然后开始合并操作：

```
➜  read-tree -m $(cat .git/a) $(cat .git/b) $(cat .git/c)
➜  write-tree
hello.txt: unmerged (ede06c6ad21dd15a253f577717792731a320c404)
hello.txt: unmerged (b1882264fc8726c9876ca2baf2c82b60fd5eb27e)
hello.txt: unmerged (bc2bb8b9e7ad1a9d4d9260648cd474f21eda5b97)
fatal: write-tree: not able to write tree
```

显然，合并遇到冲突，我们需要手工解决。先查看冲突情况：

```
➜  show-files --unmerged
100644 ede06c6ad21dd15a253f577717792731a320c404 1 hello.txt
100644 b1882264fc8726c9876ca2baf2c82b60fd5eb27e 2 hello.txt
100644 bc2bb8b9e7ad1a9d4d9260648cd474f21eda5b97 3 hello.txt
```

这个时候的 Git 还没有处理冲突的功能。根据 Linux 的脚本，我发现他使了一个叫 [merge](https://www.computerhope.com/unix/merge.htm) 命令。merge 是 RCS 提供的三路合并工具。

冲突处理过程：

```
➜  cat-file blob ede06c6ad21dd15a253f577717792731a320c404 > .hello.txt.a
➜  cat-file blob b1882264fc8726c9876ca2baf2c82b60fd5eb27e > hello.txt
➜  cat-file blob bc2bb8b9e7ad1a9d4d9260648cd474f21eda5b97 > .hello.txt.c
➜  merge hello.txt .hello.txt.a .hello.txt.c
merge: warning: conflicts during merge
➜  cat hello.txt
<<<<<<< hello.txt

b
=======

c
>>>>>>> .hello.txt.c
```

大家注意 merge 工具输出的冲突是标记，这不是 Git 发明的。

手工处理好冲突，比如同时保留 bc。然后更新暂存区：

```
➜  update-cache --add hello.txt
write-tree
➜  write-tree
32af2679dfce5faaeff80db36840bb537d6478ad
```

## 总结

早期的 Git 跟现在相比非常简陋，但它们使用核心概念跟现在的 Git 却没有太大的差别。现在的 Git 比当年更加方便，但也隐藏了更多的细节。这给我们理解 Git 带来了不小的麻烦。所谓**万变不离其宗**。我们追根溯源，回到 Git 诞生不久的年代，理解了当时 Git 的特性，也就理解了 Git 的本质。

希望本篇能给学习和使用 Git 的读者带来启发。