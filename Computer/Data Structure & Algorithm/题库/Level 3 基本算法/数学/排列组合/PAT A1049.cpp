#include <cstdio>

int main() {
  int n, base = 1, ans = 0;
  int left, now, right;

  scanf("%d", &n);

  while (n / base != 0) {
    left = n / (base * 10);
    now = n / base % 10;
    right = n % base;

    if (now == 0)
      ans += left * base;
    else if (now == 1)
      ans += left * base + right + 1;
    else
      ans += (left + 1) * base;
      
    base *= 10;
  }
  printf("%d\n", ans);
}