#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[100005];
int l_max[100005];
int r_min[100005];

int main() {
  // 读入
  int n, a;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];

  // 计算每个位置（包括）的左边最大的数
  for (int i = 1; i <= n; ++i) l_max[i] = max(arr[i], l_max[i - 1]);

  // 计算每个位置（包括）的右边最小的数
  r_min[n + 1] = 1e9 + 5;
  for (int i = n; i >= 1; --i) r_min[i] = min(arr[i], r_min[i + 1]);

  // 计算可能的主元
  vector<int> priv;
  for (int i = 1; i <= n; ++i)
    if (arr[i] >= l_max[i - 1] and arr[i] <= r_min[i + 1])
      priv.push_back(arr[i]);

  // 排序后输出
  sort(priv.begin(), priv.end());
  int sz = priv.size();
  cout << sz << '\n';
  for (int i = 0; i < sz; ++i) {
    cout << priv[i];
    if (i != sz - 1) cout << ' ';
  }
  cout << '\n';
}
