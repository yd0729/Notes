# `filecmp`

## `filecmp.cmp(f1, f2, shallow=True)`

比较名为 f1 和 f2 的文件，如果它们似乎相等则返回 `True` ，否则返回 `False` 。 如果 shallow 为真值且两个文件的 `os.stat()` 签名信息（文件类型、大小和修改时间）一致，则文件会被视为相同。 在其他情况下，如果文件大小或内容不同则它们会被视为不同。
