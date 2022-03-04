# 目录和文件操作

## `shutil.copy(src, dst, *, follow_symlinks=True)`

将文件 src 拷贝到文件或目录 dst。src 和 dst 应为路径类对象或字符串。如果 dst 指定了一个目录， 文件将使用 src 中的基准文件名拷贝到 dst 中。将返回新创建文件所对应的路径。

copy() 会拷贝文件数据和文件的权限模式 (参见os.chmod())。其他元数据，例如文件的创建和修改时间不会被保留。要保留所有原有的元数据，请改用copy2() 。

## `shutil.copy2(src, dst, *, follow_symlinks=True)`

类似于copy()，区别在于copy2() 还会尝试保留文件的元数据。

## `shutil.move(src, dst, copy_function=copy2)`

递归地将一个文件或目录 (src) 移至另一位置 (dst) 并返回目标位置。