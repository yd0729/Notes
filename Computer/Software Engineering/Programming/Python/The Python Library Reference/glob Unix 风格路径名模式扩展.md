# glob

## `glob.glob(pathname, *, root_dir=None, dir_fd=None, recursive=False)`

返回匹配 pathname 的可能为空的路径名列表，其中的元素必须为包含路径信息的字符串。pathname 可以是绝对路径 (如 /usr/src/Python-1.5/Makefile) 或相对路径 (如 ../../Tools/\*/\*. gif)，并且可包含 <mark>shell 风格的通配符</mark>。结果也将包含无效的符号链接（与在 shell 中一样）。
