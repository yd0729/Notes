#include <cstdio>
#define SIZE 2005
int main() {
  int n, exp, cnt = 0;
  double poly[SIZE] = {}, result[SIZE] = {},
         cof;  // 写在 main 里面就是为了记录一下如何初始化数组
  for (int i = 0; i < 2; ++i) {
    scanf("%d", &n);
    for (int j = 0; j < n; ++j) {
      scanf("%d %lf", &exp, &cof);
      if (i == 0)
        poly[exp] = cof;
      else
        for (int k = 0; k <= 1000; ++k) result[k + exp] += cof * poly[k];
    }
  }
  for (int i = 0; i < SIZE; ++i)
    if (result[i] != 0) ++cnt;
  printf("%d", cnt);
  if (cnt)
    for (int i = SIZE - 1; i >= 0; --i)
      if (result[i] != 0) printf(" %d %.1f", i, result[i]);
}
