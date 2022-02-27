#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[105], wolf[2], liar[2];

bool check(int ass) {
  if (ass < 0)
    return ass == -wolf[0] or ass == -wolf[1];
  else
    return ass != wolf[0] and ass != wolf[1];
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (wolf[0] = 1; wolf[0] <= n; ++wolf[0]) {
    for (wolf[1] = wolf[0] + 1; wolf[1] <= n;
         ++wolf[1]) {                // 枚举狼人的所有可能
      for (int k = 0; k < 2; ++k) {  // 有一个骗子一定是其中一个狼人
        liar[0] = wolf[k];
        for (int l = 1; l <= n; ++l) {  // 枚举另一个骗子
          if (l == wolf[1 - k] or l == liar[0]) continue;
          liar[1] = l;

          bool flag = true;
          for (int m = 1; m <= n and flag; ++m) {  // 检查是否符合所有人的断言
            if (m == liar[0] or m == liar[1])
              flag = check(-arr[m]);
            else
              flag = check(arr[m]);
          }
          if (flag) {
            cout << wolf[0] << " " << wolf[1];
            return 0;
          }
        }
      }
    }
  }
  cout << "No Solution";
}