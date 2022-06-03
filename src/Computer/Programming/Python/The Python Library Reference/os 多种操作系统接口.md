# 文件和目录

## `os.chdir(path)`

将当前工作目录更改为 path．

```python
os.chdir(os.path.dirname(__file__)) # set cwd to script directory
```

## `os.getcwd()`

返回表示当前工作目录的字符串．

## `os.walk(top, topdown=True, onerror=None, followlinks=False)`

生成目录树中的文件名，方式是按上-> 下或下-> 上顺序浏览目录树．对于以 top 为根的目录树中的 每个目录（包括 top 本身），它都会生成一个三元组 (dirpath, dirnames, filenames)．

dirpath 是表示目录路径的字符串．dirnames 是 dirpath 中子目录名称组成的列表（不包括 `.` 和 `..`）．ﬁlenames 是 dirpath 中非目录文件名称组成的列表．请注意列表中的名称不带路径部分．要获取 `dirpath` 中文件或目录的完整路径（以 top 打头），请执行 `os.path.join(dirpath, name)`．

## `os.makedirs(name, mode=511, exist_ok=False)`

递归目录创建函数．与 `mkdir()` 类似，但会自动创建到达最后一级目录所需要的中间目录．
