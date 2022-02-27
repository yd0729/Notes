#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int pow(int x, int p) {
  int ans = 1;

  while (p > 0) {
    if (p & 1) ans *= x;
    x *= x;
    p >>= 1;
  }

  return ans;
}

int n, k, p, max_num, max_sum;
vector<int> ans, now;

void dfs(int num, int cnt, int sum, int sum_p) {
  if (cnt >= k or sum_p >= n) {
    if (cnt == k and sum_p == n and sum > max_sum) {
      ans = now;
      max_sum = sum;
    }
    return;
  }

  for (int i = num; i >= 1 and pow(i, p) * (k - now.size()) + sum_p >= n; --i) {
    now.push_back(i);
    dfs(i, cnt + 1, sum + i, sum_p + pow(i, p));
    now.pop_back();
  }
}

int main() {
  cin >> n >> k >> p;

  // 确定可能的最大值
  while (pow(max_num + 1, p) + k - 1 <= n) ++max_num;

  dfs(max_num, 0, 0, 0);

  if (ans.size() == 0)
    cout << "Impossible\n";
  else {
    cout << n << " = ";
    for (auto i = ans.begin(); i != ans.end(); ++i) {
      cout << *i << "^" << p;
      if (i + 1 != ans.end()) cout << " + ";
    }
    cout << "\n";
  }
}