# `stdlib.h`

## `qsort`

```c
void qsort ( void * base, size_t num, size_t size, int ( * comparator ) ( const void *, const void * ) );
```

前3个参数分别是待排序的数组起始地址、元素个数和每个元素的大小。最后一个参数比较特别，是一个指向函数的指针，该函数应当具有这样的形式：

```c
int cmp(const void *, const void *) { … }
```

这里的新内容是指向常数的“万能”的指针：`const void *`，它可以通过强制类型转化变成任意类型的指针。如果排序的对象是整型数组，则这样写：

```c
int cmp ( const void *a , const void *b ) {
 return *(int *)a - *(int *)b;
```

一般地，需要先把参数 `a` 和 `b` 转化为真实的类型，然后让 `cmp` 函数当 `a<b` 、 `a=b` 和 `a>b` 时分别返回负数、 0 和正数即可。