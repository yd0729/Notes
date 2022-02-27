#include <cstdio>
char color[] = {'S', 'H', 'C', 'D', 'J'};
int main() {
  int result[2][60], order[60];
  int t, j = 0;
  scanf("%d", &t);
  for (int i = 1; i <= 54; ++i) result[1][i] = i;
  for (int i = 1; i <= 54; ++i) scanf("%d", &order[i]);
  for (; t--; j = 1 - j)
    for (int i = 1; i <= 54; ++i) result[j][order[i]] = result[1 - j][i];
  for (int i = 1; i <= 54; ++i) {
    printf("%c%d", color[(result[1 - j][i] - 1) / 13],
           (result[1 - j][i] - 1) % 13 + 1);
    if (i != 54) putchar(' ');
  }
}