# 读取

## 无表头

`header=None`

```python
df = pd.read_csv(filename, encoding='gbk', header=None)
```

# 按行 / 列遍历

```python
for index, row in csv.iterrows(): # index 是行数
  pass
for index, row in csv.iteritems():
  pass
```
