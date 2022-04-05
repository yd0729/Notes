---
publish: true
creat:
last modify:
---
# scanf, fscanf, sscanf, scanf_s, fscanf_s, sscanf_s

> # 参考
> https://zh.cppreference.com/w/c/io/fscanf
> https://www.cnblogs.com/yjz6/p/9799610.html

前 3 个废弃了，直接忽略．

## 定义

```c
int scanf_s(const char *restrict format, ...);
int fscanf_s(FILE *restrict stream, const char *restrict format, ...);
int sscanf_s(const char *restrict buffer, const char *restrict format, ...);
```

分别从 stdin / 文件 / 字符串 读取．

 `%c` 、 `%s` 及 `%[` 转换指定符要求 2 个参数，第 2 个参数是要读取的长度．

`restrict` 关键字可以看[维基](https://en.wikipedia.org/wiki/Restrict)．

## 参数

### format

格式：

1. %
2. （可选）赋值抑制字符 * ：只读，不赋值．
3. （可选）指定最大域宽的整数数字（大于零）．
4. (可选)指定接收参数大小的长度修饰符 l．
5. 转换格式说明符．

### 返回值

成功赋值的参数数量，或 EOF ．

## 例子

有空格的字符串

```c
scanf("%[^\n]%*c",str);
```