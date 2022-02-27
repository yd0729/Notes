#include <cstdio>
#define M 1005
double poly[M];
int main() {
  double q;
  int k, p, cnt = 0;
  for (int i = 0; i < 2; ++i) {
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d %lf", &p, &q);
      poly[p] += q;
    }
  }
  for (int i = 0; i < M; ++i)
    if (poly[i] != 0) ++cnt;
  printf("%d", cnt);
  if (cnt)
    for (int i = M - 1; i >= 0; --i)
      if (poly[i] != 0) printf(" %d %.1f", i, poly[i]);
}
