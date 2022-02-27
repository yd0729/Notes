# 《Pro Git》笔记

## 起步

### 关于版本控制

在本书所展示的例子中，我们对保存着软件源代码的文件作版本控制，但实际上，你可以对任何类型的文件进行版本控制。

#### 本地版本控制系统

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-02-04 15.17.56.png" alt="截屏2022-02-04 15.17.56" style="zoom:25%;" />

其中最流行的一种叫做 RCS，现今许多计算机系统上都还看得到它的踪影。 **RCS 的工作原理是在硬盘上保存补丁集（补丁是指文件修订前后的变化）**：通过应用所有的补丁，可以重新计算出各个版本的文件内容。

#### 集中化的版本控制系统（Centralized Version Control Systems， CVCS）

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-02-04 15.19.15.png" alt="截屏2022-02-04 15.19.15" style="zoom:33%;" />

让在不同系统上的开发者协同工作。

#### 分布式版本控制系统（Distributed Version Control System， DVCS）

客户端并不只提取最新版本的文件快照， 而是把代码仓库完整地镜像下来，包括完整的历史记录。 这么一来，任何一处协同工作用的服务器发生故障，事后都可以用任何一个镜像出来的本地仓库恢复。 因为每一次的克隆操作，实际上都是一次对代码仓库的完整备份。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-02-04 15.22.23.png" alt="截屏2022-02-04 15.22.23" style="zoom:33%;" />

**许多这类系统都可以指定和若干不同的远端代码仓库进行交互。**籍此，你就可以在同一个项目中，分别和不同工作小组的人相互协作。

## Git 是什么？

### 直接记录快照，而非差异比较

其它大部分系统以文件变更列表的方式存储信息，这类系统（CVS、Subversion、Perforce、Bazaar 等等） 将它们存储的信息看作是一组基本文件和每个文件随时间逐步累积的差异 （它们通常称作 **基于差异（delta-based）** 的版本控制）。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-02-04 15.55.29.png" alt="截屏2022-02-04 15.55.29" style="zoom:50%;" />

Git 更把数据看作是对小型文件系统的一系列快照。 在 Git 中，每当你提交更新或保存项目状态时，它基本上就会对当时的全部文件创建一个快照并保存这个快照的索引。 为了效率，如果文件没有修改，Git 不再重新存储该文件，而是只保留一个链接指向之前存储的文件。 Git 对待数据更像是一个 **快照流**。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-02-04 15.56.32.png" alt="截屏2022-02-04 15.56.32" style="zoom:50%;" />

### Git 保证完整性

Git 中所有的数据在存储前都**计算校验和**，然后以校验和来引用。**Git 用以计算校验和的机制叫做 SHA-1 散列（hash，哈希）**。 这是一个**由 40 个十六进制字符（0-9 和 a-f）组成的字符串，基于 Git 中文件的内容或目录结构计算出来。** SHA-1 哈希看起来是这样：

    24b9da6552252987aa493b52f8696cd6d3b00373

Git 中使用这种哈希值的情况很多，你将经常看到这种哈希值。 实际上，**Git 数据库中保存的信息都是以文件内容的哈希值来索引，而不是文件名。**

### 3 种状态

Git 有三种状态，你的文件可能处于其中之一： **已提交（committed）**、**已修改（modified）** 和 **已暂存（staged）**。

- 已修改表示修改了文件，但还没保存到数据库中。
- 已暂存表示对一个已修改文件的当前版本做了标记，使之包含在下次提交的快照中。
- 已提交表示数据已经安全地保存在本地数据库中。

这会让我们的 Git 项目拥有三个阶段：**工作区**、**暂存区**以及 **Git 目录**。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-02-04 17.36.43.png" alt="截屏2022-02-04 17.36.43" style="zoom:50%;" />

- 工作区是对项目的某个版本独立提取出来的内容。 这些从 Git 仓库的压缩数据库中提取出来的文件，放在磁盘上供你使用或修改。
- 暂存区是一个文件，保存了下次将要提交的文件列表信息，一般在 Git 仓库目录中。 按照 Git 的术语叫做“索引”，不过一般说法还是叫“暂存区”。
- Git 仓库目录是 Git 用来保存项目的元数据和对象数据库的地方。 这是 Git 中最重要的部分，从其它计算机克隆仓库时，复制的就是这里的数据。

## 初次运行 Git 前的配置

Git 自带一个 `git config` 的工具来帮助设置控制 Git 外观和行为的配置变量。 这些变量存储在三个不同的位置：

1. `/etc/gitconfig` 文件: 包含系统上每一个用户及他们仓库的通用配置。 如果在执行 `git config` 时带上 `--system` 选项，那么它就会读写该文件中的配置变量。 （由于它是系统配置文件，因此你需要管理员或超级用户权限来修改它。）
2. `~/.gitconfig` 或 `~/.config/git/config` 文件：只针对当前用户。 你可以传递 `--global` 选项让 Git 读写此文件，这会对你系统上 **所有** 的仓库生效。
3. 当前使用仓库的 Git 目录中的 config 文件（即 `.git/config`）：针对该仓库。 你可以传递 `--local` 选项让 Git 强制读写此文件，虽然默认情况下用的就是它。 （当然，你需要进入某个 Git 仓库中才能让该选项生效。）

每一个级别会覆盖上一级别的配置，所以 .git/config 的配置变量会覆盖 /etc/gitconfig 中的配置变量。

```sh
git config --list --show-origin
```

查看所有的配置以及它们所在的文件。

### 用户信息

```sh
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```

### 文本编辑器

### 默认分支名称

```sh
git config --global init.defaultBranch main
```

### 检查配置信息

```sh
$ git config --list
user.name=John Doe
user.email=johndoe@example.com
color.status=auto
color.branch=auto
color.interactive=auto
color.diff=auto
...
```

可能会出现重复的变量名，因为 Git 会从不同的文件中读取同一个配置。

```sh
$ git config user.name
John Doe
```

使用 `git config <key>` 来检查 Git 的某一项配置。

```sh
$ git config --show-origin rerere.autoUpdate
file:/home/johndoe/.gitconfig false
```

`--show-origin` 可以显示配置来自哪个文件。

### 获取帮助

显示 Git 命令的综合手册（manpage）。

```sh
$ git help <verb>
git <verb> --help
man git-<verb>
```

如果你不需要全面的手册，只需要可用选项的快速参考，那么可以用 `-h` 选项。

```sh
git add -h
```

## Git 基础

### 获取 Git 仓库

#### 在已存在目录中初始化仓库

```sh
git init
```

#### 克隆现有的仓库

```sh
git clone https://github.com/libgit2/libgit2 mylibgit
```

## 向仓库中记录变更

工作目录下的每一个文件都不外乎这两种状态：**已跟踪** 或 **未跟踪**。

**已跟踪的文件是指那些被纳入了版本控制的文件，在上一次快照中有它们的记录**，在工作一段时间后， 它们的状态可能是未修改，已修改或已放入暂存区。简而言之，已跟踪的文件就是 Git 已经知道的文件。

**工作目录中除已跟踪文件外的其它所有文件都属于未跟踪文件，它们既不存在于上次快照的记录中，也没有被放入暂存区。** 初次克隆某个仓库的时候，工作目录中的所有文件都属于已跟踪文件，并处于未修改状态，因为 Git 刚刚检出了它们， 而你尚未编辑过它们。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-02-04 19.45.57.png" alt="截屏2022-02-04 19.45.57" style="zoom:50%;" />

### 检查文件状态

```sh
git status
```

选项 `-s` 或 `--short` 可以让输出更简洁。

### 跟踪新文件 / 暂存已修改的文件

```sh
git add <file>
```

### 忽略文件

文件 .gitignore 的格式规范如下：

1. 所有空行或者以 # 开头的行都会被 Git 忽略。
2. 可以使用标准的 glob 模式匹配，它会递归地应用在整个工作区中。所谓的 glob 模式是指 shell 所使用的简化了的正则表达式。 星号（\*）匹配零个或多个任意字符；[abc] 匹配任何一个列在方括号中的字符 （这个例子要么匹配一个 a，要么匹配一个 b，要么匹配一个 c）； 如果在方括号中使用短划线分隔两个字符， 表示所有在这两个字符范围内的都可以匹配（比如 [0-9] 表示匹配所有 0 到 9 的数字）。问号（?）只匹配一个任意字符；使用两个星号（\*\*）表示匹配任意中间目录，比如 a/\*\*/z 可以匹配 a/z 、 a/b/z 或 a/b/c/z 等。
3. 匹配模式可以以（/）开头防止递归。
4. 匹配模式可以以（/）结尾指定目录。
5. 要忽略指定模式以外的文件或目录，可以在模式前加上叹号（!）取反。

```sh
# 忽略所有的 .a 文件
*.a

# 但跟踪所有的 lib.a，即便你在前面忽略了 .a 文件
!lib.a

# 只忽略当前目录下的 TODO 文件，而不忽略 subdir/TODO
/TODO

# 忽略任何目录下名为 build 的文件夹
build/

# 忽略 doc/notes.txt，但不忽略 doc/server/arch.txt
doc/*.txt

# 忽略 doc/ 目录及其所有子目录下的 .pdf 文件
doc/**/*.pdf
```
