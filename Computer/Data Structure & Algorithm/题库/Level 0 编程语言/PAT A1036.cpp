#include <cstdio>
struct {
  char name[50], major[50];
  int grade;
} f, m, s;
int main() {
  m.grade = 9999;
  f.grade = -9999;
  int n;
  char sex;
  scanf("%d", &n);
  while (n--) {
    scanf("%s %c %s %d\n", s.name, &sex, s.major, &s.grade);
    if (sex == 'M' and s.grade < m.grade)
      m = s;
    else if (sex == 'F' and s.grade > f.grade)
      f = s;
  }
  f.grade == -9999 ? printf("Absent\n") : printf("%s %s\n", f.name, f.major);
  m.grade == 9999 ? printf("Absent\n") : printf("%s %s\n", m.name, m.major);
  f.grade == -9999 || m.grade == 9999 ? printf("NA\n")
                                      : printf("%d\n", f.grade - m.grade);
}