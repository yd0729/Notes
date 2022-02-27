#include <cstdio>

struct Student {
  char name[15];
  char id[15];
  int score;
} tmp, max_score, min_score;

int main() {
  int n;
  scanf("%d", &n);
  max_score.score = -1;
  min_score.score = 101;
  for (int i = 0; i < n; i++) {
    scanf("%s%s%d", &tmp.name, &tmp.id, &tmp.score);
    if (tmp.score > max_score.score) max_score = tmp;
    if (tmp.score < min_score.score) min_score = tmp;
  }
  printf("%s %s\n", max_score.name, max_score.id);
  printf("%s %s\n", min_score.name, min_score.id);
  return 0;
}