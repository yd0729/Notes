#include <cstdio>
int main() {
  int t;
  scanf("%d", &t);
  long long a, b, c, sum;
  for (int i = 1; i <= t; ++i) {
    scanf("%lld%lld%lld", &a, &b, &c);
    sum = a + b;
    if (a > 0 and b > 0 and sum < 0)
      printf("Case #%d: true\n", i);
    else if (a < 0 and b < 0 and sum >= 0)
      printf("Case #%d: false\n", i);
    else if (sum > c)
      printf("Case #%d: true\n", i);
    else
      printf("Case #%d: false\n", i);
  }
}