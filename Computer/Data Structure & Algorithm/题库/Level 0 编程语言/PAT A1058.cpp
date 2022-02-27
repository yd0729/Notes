#include <cstdio>
struct m {
  int g, s, k;
};
int main() {
  m a, b;
  scanf("%d.%d.%d %d.%d.%d", &a.g, &a.s, &a.k, &b.g, &b.s, &b.k);
  a.g += b.g;
  a.s += b.s;
  a.k += b.k;
  if (a.k >= 29) {
    a.s += a.k / 29;
    a.k %= 29;
  }
  if (a.s >= 17) {
    a.g += a.s / 17;
    a.s %= 17;
  }
  printf("%d.%d.%d", a.g, a.s, a.k);
}