# URL 转码

URL 转码函数的功能是接收程序数据并通过对特殊字符进行转码并正确编码非 ASCII 文本来将其转为可以安全地用作 URL 组成部分的形式。它们还支持逆转此操作以便从作为 URL 组成部分的内容中重建原 始数据。

## `urllib.parse.quote(string, safe=’/’, encoding=None, errors=None)`

使用 `%xx` 转义符替换 string 中的特殊字符。字母、数字和 `'_.-~'` 等字符一定不会被转码。在默认 情况下，此函数只对 URL 的路径部分进行转码。可选的 safe 形参额外指定不应被转码的 ASCII 字 符 --- 其默认值为 `'/'`。

## `urllib.parse.unquote(string, encoding=’utf-8’, errors=’replace’)`

将 `%xx` 转义符替换为其单字符等价物。

