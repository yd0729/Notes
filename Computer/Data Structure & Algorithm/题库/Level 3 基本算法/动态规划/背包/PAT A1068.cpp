#include <algorithm>
#include <cstdio>
using namespace std;
const int max_n = 10010;
const int max_v = 110;
int w[max_n], dp[max_v];  // w 为钱币的价值
bool choice[max_n][max_v];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
  sort(w + 1, w + 1 + n, greater<int>());  // 从大到小排列
  for (int i = 1; i <= n; ++i) {           // 每一轮多考虑一件物品
    for (int v = m; v >= w[i]; v--) {  // 从后到前，因为要用到上一轮的结果
      if (dp[v] <= dp[v - w[i]] + w[i]) {  // 等于时也要放，因为这个序列一定更小
        dp[v] = dp[v - w[i]] + w[i];
        choice[i][v] = true;  // 在大小为 v 的背包中放入第 i 件物品
      }
    }
  }
  if (dp[m] != m)
    printf("No Solution");
  else {
    for (; n and m; --n) {
      if (choice[n][m]) {
        printf("%d", w[n]);
        if (m -= w[n]) printf(" ");
      }
    }
  }
}