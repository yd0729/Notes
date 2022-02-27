#include <cstdio>

int main() {
  int school[100010] = {};
  int n;
  scanf("%d", &n);
  int id = 0, score = 0;
  int max_id = 1, max_score = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &id, &score);
    school[id] += score;
    if (school[id] > max_score) {
      max_id = id;
      max_score = school[id];
    }
  }
  printf("%d %d", max_id, max_score);
  return 0;
}