#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int hsh[210];  // 将喜欢的颜色序列映射为递增序列，不喜欢的颜色映射为-1
int a[10010], dp[10010];
int main() {
  int n, m, x;
  scanf("%d%d", &n, &m);
  memset(hsh, -1, sizeof(hsh));
  for (int i = 0; i < m; ++i) {
    scanf("%d", &x);
    hsh[x] = i;  // 将喜欢的颜色按顺序映射到递增序列0 1 2 ...
  }
  int l, num = 0;  // num 存放颜色序列中喜欢的颜色的总数（暂不考虑顺序）
  scanf("%d", &l);
  for (int i = 0; i < l; ++i) {
    scanf("%d", &x);
    if (hsh[x] >= 0) a[num++] = hsh[x];
  }
  // 以下全部为LIS问题的模板
  int ans = -1;
  for (int i = 0; i < num; ++i) {
    dp[i] = 1;  // 以 i 结尾（包含 i）的 IS
    for (int j = 0; j < i; ++j) {
      if (a[j] <= a[i] and dp[i] < dp[j] + 1)  // 由于可以重复，所以这里是 <=
        dp[i] = dp[j] + 1;
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
}