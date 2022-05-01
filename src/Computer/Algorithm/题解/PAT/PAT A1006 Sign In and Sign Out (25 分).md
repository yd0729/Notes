# 1006 Sign In and Sign Out (25 分)

At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

## Input Specification

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer $M$, which is the total number of records, followed by $M$ lines, each in the format:

    ID_number Sign_in_time Sign_out_time

where times are given in the format `HH:MM:SS`, and `ID_number` is a string with no more than 15 characters.

## Output Specification

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

## Sample Input

    3
    CS301111 15:30:28 17:00:10
    SC3021234 08:00:00 11:25:25
    CS301133 21:45:00 21:58:40

## Sample Output

    SC3021234 CS301133

## 题解

### 题意

给出 n 个人进入和出去的时间，求最早进来和最晚出去的人的 `id`。

### 思路

遍历一遍，记录来得最早和走得最晚的人。**时间按照字符串输入进来就可以直接比较大小，不用转换成秒。**

### 代码

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  string id, lock, unlock, in_time, out_time, min_time = "24:00:00",
                                              max_time = "00:00:00";

  for (int i = 0; i < n; ++i) {
    cin >> id >> in_time >> out_time;

    if (in_time < min_time) {
      min_time = in_time;
      unlock = id;
    }

    if (out_time > max_time) {
      max_time = out_time;
      lock = id;
    }
  }

  cout << unlock << " " << lock;
}
```
