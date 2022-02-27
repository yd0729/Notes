# 更新 fork 的 repo 和 pull request

## 保持和源仓库的同步更新

添加远程的源仓库

```bash
git remote add upstream git@github.com:xxx/some_tools.git
```

查看 remote

```bash
git remote -v
```

从源仓库 `fetch` 代码，会被存储在一个本地分支 `upstream/master`

```bash
git fetch upstream
```

合并到自己的本地分支

```bash
git merge upstream/master
```

push 代码到自己的分支远程仓库

```bash
git push
```

## 将代码提交到源仓库的 pull request

在自己的分支修改好代码后，add，commit，push。

```bash
git add .
git commit -m "合并修改"
git push
```

这时候来到自己 `github` 代码库上方有提示你刚提交了代码，有`pull request`的提示。

进去之后看到一个类似这样的界面：

[<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/61d1c8136eb9e.png " alt="61d1c8136eb9e.png " style="zoom:100%;" />
