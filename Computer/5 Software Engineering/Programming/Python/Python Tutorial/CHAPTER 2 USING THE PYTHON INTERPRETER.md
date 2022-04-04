---
tag: python, python interpreter
---

# CHAPTER 2 | USING THE PYTHON INTERPRETER

## 2.1 Invoking the Interpreter

```sh
python -c command [arg] ...
```

执行命令．由于 Python 语句经常包含空格等被 shell 特殊对待的字符， 建议用单引号标注整个 command ．

```sh
python -i script [arg] ...
```

执行脚本，`-i` 是在交互模式下．

```sh
python -m module [arg] ...
```

把模块当做脚本使用，<mark>可以使用相对导入</mark>．

### 2.1.1 Argument Passing

1. 脚本的路径（或者是模块的源文件的绝对路径）和后面的参数会被当做 `List[str]` 传递给 `sys.argv` ．

2. 如果执行的是命令的话， `-c` 也会保留．

### 2.1.2 Interactive Mode

## 2.2 The Interpreter and Its Environment

### 2.2.1 Source Code Encoding

```python
# -*- coding: encoding -*-
```

写在第 1 行，默认是 UTF-8 ．

```python
#!/usr/bin/env python3
# -*- coding: cp1252 -*-
```

如果是可执行的 Python 脚本，就写在第 2 行．

```sh
chmod +x myscript.py
```

给可执行的权限．
