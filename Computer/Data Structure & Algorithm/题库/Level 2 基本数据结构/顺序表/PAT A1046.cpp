#include <algorithm>
#include <iostream>
using namespace std;
int prefix[100005];  // 到 1 的距离（按照一个方向）
int main() {
  int n, m, sum, a, b;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &prefix[i + 1]);
    prefix[i + 1] += prefix[i];
  }
  for (cin >> m; m--;) {
    scanf("%d%d", &a, &b);
    if (b < a) swap(a, b);
    sum = prefix[b] - prefix[a];
    printf("%d\n", min(sum, prefix[n + 1] - sum));
  }
}