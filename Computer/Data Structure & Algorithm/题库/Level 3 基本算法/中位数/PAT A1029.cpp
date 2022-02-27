#include <iostream>
using namespace std;
long int arr[200005];
int main() {
  cin.tie(nullptr);  // 关闭流同步，否则最后一个测试点会超时
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  int n1, n2, cur_1 = 0, cur_2 = 0, mid, ans, t;
  cin >> n1;
  for (int i = 0; i < n1; ++i) cin >> arr[i];
  cin >> n2;
  mid = (n1 + n2 + 1) / 2;
  while (cur_1 + cur_2 < mid and cur_2 < n2) {  // 在线处理第二个数组
    cin >> t;
    while (cur_1 < n1 and cur_1 + cur_2 < mid and arr[cur_1] <= t)
      ans = arr[cur_1++];
    if (cur_1 + ++cur_2 <= mid) ans = t;
  }
  while (cur_1 + cur_2 < mid) ans = arr[cur_1++];
  cout << ans;
}