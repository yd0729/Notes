#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int cnt = 0, n;
  double sum = 0, x;
  char s1[233], s2[233];

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s1);         // 读入的字符串
    sscanf(s1, "%lf", &x);   // 按照double读入到x中
    sprintf(s2, "%.2f", x);  // 按照.2f的格式打印到另一个字符串中
    s2[strlen(s1)] = '\0';

    if (x > 1000 or x < -1000 or strcmp(s1, s2) != 0)
      printf("ERROR: %s is not a legal number\n", s1);
    else {
      ++cnt;
      sum += x;
    }
  }

  if (cnt == 0)
    printf("The average of 0 numbers is Undefined\n");
  else
    printf("The average of %d number%s is %.2f\n", cnt, cnt == 1 ? "" : "s",
           sum / cnt);
}