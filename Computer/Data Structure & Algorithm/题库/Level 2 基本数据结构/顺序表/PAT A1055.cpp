#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 100010;
int age[max_n];
struct {
  int age, w;
  char name[10];
} p[max_n];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%s%d%d", p[i].name, &p[i].age, &p[i].w);
  sort(p, p + n, [](auto &a, auto &b) {
    if (a.w != b.w)
      return a.w > b.w;
    else if (a.age != b.age)
      return a.age < b.age;
    return strcmp(a.name, b.name) < 0;
  });
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (age[p[i].age] < 100) {
      age[p[i].age]++;
      p[cnt++] = p[i];
    }
  }
  for (int i = 1; i <= k; i++) {
    int m, age_l, age_r, c = 0;
    scanf("%d%d%d", &m, &age_l, &age_r);
    printf("Case #%d:\n", i);
    for (int j = 0; j < cnt and c < m; j++) {
      if (p[j].age >= age_l and p[j].age <= age_r) {
        printf("%s %d %d\n", p[j].name, p[j].age, p[j].w);
        c++;
      }
    }
    if (c == 0) printf("None\n");
  }
}