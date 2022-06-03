## `os.path.exists(path)`

如果 path 指向一个已存在的路径或已打开的文件描述符，返回 True．对于失效的符号链接，返回 False．

## `os.path.join(path, *paths)`

智能地拼接一个或多个路径部分．返回值是 path 和 *paths 的所有成员的拼接，其中每个非空部分后面都紧跟一个目录分隔符，最后一个部分除外，这意味着如果最后一个部分为空，则结果将以分隔符结尾．如果某个部分为绝对路径，则之前的所有部分会被丢弃并从绝对路径部分开始继续拼接．

## `os.path.split(path)`

将路径 path 拆分为一对，即 (head, tail)，其中，tail 是路径的最后一部分，而 head 里是除最 后部分外的所有内容．tail 部分不会包含斜杠，如果 path 以斜杠结尾，则 tail 将为空．如果 path 中 没有斜杠，head 将为空．如果 path 为空，则 head 和 tail 均为空．head 末尾的斜杠会被去掉，除非 它是根目录（即它仅包含一个或多个斜杠）．在所有情况下，join(head, tail) 指向的位置都 与 path 相同（但字符串可能不同）．

## `os.path.dirname(path)`

返回路径 path 的目录名称．这是将 path 传入函数 `split()` 之后，返回的一对值中的第一个元素．

## `os.path.isabs(path)`

如果 path 是一个绝对路径，则返回 True．
