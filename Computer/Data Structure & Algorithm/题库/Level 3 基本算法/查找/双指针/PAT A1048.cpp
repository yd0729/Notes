#include <algorithm>
#include <cstdio>
using namespace std;
int a[100010], m, n;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  int i = 0, j = n - 1;
  while (i < j) {
    if (a[i] + a[j] == m)
      break;  // 找到a[i]与a[j]的和为m，退出循环
    else if (a[i] + a[j] < m)
      ++i;
    else
      --j;
  }
  if (i < j)
    printf("%d %d\n", a[i], a[j]);
  else
    printf("No Solution\n");
}