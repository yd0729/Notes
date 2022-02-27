#include <algorithm>
#include <cstdio>

using namespace std;

struct {
  char name[11], id[11];
  int grade;
} s[50];

int main() {
  int n, left, right;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s %s %d", s[i].name, s[i].id, &s[i].grade);
  scanf("%d%d", &left, &right);

  sort(s, s + n, [](auto &a, auto &b) { return a.grade > b.grade; });

  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (s[i].grade >= left and s[i].grade <= right) {
      printf("%s %s\n", s[i].name, s[i].id);
      flag = true;
    }
  }
  if (flag == false) printf("NONE\n");
}