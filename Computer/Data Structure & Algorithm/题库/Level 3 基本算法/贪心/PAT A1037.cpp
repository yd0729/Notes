#include <algorithm>
#include <cstdio>
using namespace std;
int a[2][100005], len[2];
int main() {
  int c, p, sum = 0;
  for (int i = 0; i < 2; i++) {
    scanf("%d", len + i);
    for (int j = 0; j < len[i]; j++) scanf("%d", &a[i][j]);
    sort(a[i], a[i] + len[i]);
  }
  for (int i = 0, j = 0;
       i < len[0] and j < len[1] and a[0][i] < 0 and a[1][j] < 0; ++i, ++j)
    sum += a[0][i] * a[1][j];
  for (int i = len[0] - 1, j = len[1] - 1;
       i >= 0 and j >= 0 and a[0][i] > 0 and a[1][j] > 0; --i, --j)
    sum += a[0][i] * a[1][j];
  printf("%d", sum);
}