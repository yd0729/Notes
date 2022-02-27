#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, num, left, right, sum, cur_sum, cur_left;
  cin >> n >> num;
  cur_sum = sum = cur_left = left = right = num;
  for (int i = 1; i < n; ++i) {
    cin >> num;
    if (num >= 0 and cur_sum < 0)  // 从当前开始
      cur_left = cur_sum = num;
    else  // 继续累计
      cur_sum += num;
    if (cur_sum > sum) {  // 更新最大值
      sum = cur_sum;
      left = cur_left;
      right = num;
    }
    if (sum < 0) right = num;
  }
  cout << max(sum, 0) << " " << left << " " << right;
}
