# CHAPTER 4 | MORE CONTROL FLOW TOOLS

## 4.1 `if` Statements

## 4.2 `for` Statements

在遍历时修改 collection 是 tricky．

```python
# Create a sample collection
users = {'Hans': 'active', 'Éléonore': 'inactive', '   ': 'active'}

# Strategy: Iterate over a copy
for user, status in users.copy().items():
	if status == 'inactive':
		del users[user]

# Strategy: Create a new collection
active_users = {}
for user, status in users.items():
	if status == 'active':
		active_users[user] = status
```

1. 在拷贝上遍历，修改原 collection．
2. 在原 collection 上遍历，创建一个新的 collection．

## 4.3 The `range()` Function

```python
>>> list(range(-10, -100, -30))
[-10, -40, -70]
>>> sum(range(4))
6
```

1. 第 3 个参数是步长．
2. `range()` 可以转换成 `list` ，但不是 `list `．它是 `iterable` .
3. 大多数情况下用 `enumerate()` 更方便．

## 4.4 `break` and `continue` Statements, and `else` Clauses on Loops

```python
>>> for n in range(2, 10):
... 	for x in range(2, n):
... 		if n % x == 0:
... 			print(n, 'equals', x, '*', n//x)
... 			break
... 	else:
... 		# loop fell through without finding a factor
... 		print(n, 'is a prime number')
...
2 is a prime number
3 is a prime number
4 equals 2 * 2
5 is a prime number
6 equals 2 * 3
7 is a prime number
8 equals 2 * 4
9 equals 3 * 3
```

<mark>循环语句都可以有 `else`</mark> ，在循环条件不满足时进入，但如果被 `break` 了就不会进入．

## 4.5 `pass` Statements

```python
while True:
    pass
```

Busy-wait for keyboard interrupt (Ctrl+C).

```python
class MyEmptyClass:
    pass
```

a minimal class.

```python
def initlog(*args):
    pass  # Remember to implement this!
```

a place-holder.

## <mark>4.6 `match` Statements</mark>

```python
def http_error(status):
	match status:
    case 400:
      return "Bad request"
    case 404:
      return "Not found"
    case 418:
      return "I'm a teapot"
    case _:
      return "Something's wrong with the internet"
```

`case _` 相当于 `default` ，可以没有．

```python

```
