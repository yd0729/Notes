# CHAPTER 3 | AN INFORMAL INTRODUCTION TO PYTHON

## 3.1 Using Python as a Caculator

### 3.1.1 Numbers

```python
>>> 17 // 3 # floor division discards the fractional part
5
```

除了整型和浮点数，Python 也支持十进制小数、分数和复数（比如 $3+5i$ 表示成 `3+5j`）．

### 3.1.2 Strings

字符串是 immutable ．

```python
print("""\
Usage: thingy [OPTIONS]
	-h													Display this usage message
	-H hostname 								Hostname to connect to
""")
```

多行的字符串（用单引号也行），那个 `\` 可以使不换行，看起来更规整．

```python
>>> text = ('Put several strings within parentheses '
...         'to have them joined together.')
>>> text
'Put several strings within parentheses to have them joined together.'
```

两个挨着的字面值字符串会自动连接到一起，可以用来隔断长字符串．

### 3.1.3 Lists

最多用途的 compound data types．

```python
>>> squares[:]
[1, 4, 9, 16, 25]
```

返回一个 shallow copy （浅拷贝，详见 [copy](/Users/yangdong/KMS/Computer/Software Engineering/Programming/Python/The Python Library Reference/copy – Shallow and deep copy operations.md)）．

```python
>>> squares + [36, 49, 64, 81, 100]
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```

支持 concatenation．

```python
>>> letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
>>> letters
['a', 'b', 'c', 'd', 'e', 'f', 'g']
>>> # replace some values
>>> letters[2:5] = ['C', 'D', 'E']
>>> letters
['a', 'b', 'C', 'D', 'E', 'f', 'g']
>>> # now remove them
>>> letters[2:5] = []
>>> letters
['a', 'b', 'f', 'g']
>>> # clear the list by replacing all the elements with an empty list
>>> letters[:] = []
>>> letters []
```

Assignment to slices．

## 3.2 First Steps Towards Programming

```python
a, b = 0, 1
while a < 1000:
    print(a, end=',')
    a, b = b, a + b
```

Fibonacci．

multiple assignment，首先计算右侧的表达式，然后左侧的各个变量同时被赋值．
