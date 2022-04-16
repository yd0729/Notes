# 1001 A+B Format (20 分)

Calculate $a+b$ and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

## Input Specification

Each input file contains one test case. Each case contains a pair of integers $a$ and $b$ where $-10^6 \le a, b \le 10^6$. The numbers are separated by a space.

## Output Specification

For each test case, you should output the sum of $a$ and $b$ in one line. The sum must be written in the standard format.

## Sample Input

    -1000000 9

## Sample Output

    -999,991

## 题解

### 题意

计算 $A+B$，输出时每隔三位在数字间加上","。

### 思路

从前到后输出每一位，如果当前位满足 `(i + 1) % 3 == len % 3`（ `i` 从 0 开始），那么就应该在这位之后输出一个逗号，排除负号和最后一位的情况。

### 代码

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  string s = to_string(a + b);
  for (int i = 0, len = s.size(); i < len; i++) {
    cout << s[i];
    if (s[i] == '-' or i == len - 1)  // 负号或者最后一位不用加逗号
      continue;
    if ((i + 1) % 3 == len % 3)  // i + 1 表示第几个位置
      cout << ",";
  }
}
```
