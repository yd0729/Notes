#include <cstdio>

int main() {
  int n;
  double v, ans = 0;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &v);            // 第 i 位的值为 v
    ans += v * i * (n + 1 - i);  // 第 i 位的总出现次数为 v * i * (n + 1 - i)
  }

  printf("%.2f\n", ans);
}