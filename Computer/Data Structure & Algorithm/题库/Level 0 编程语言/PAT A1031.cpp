#include <cstdio>
#include <cstring>
using namespace std;
int main() {
  char s[100];
  scanf("%s", s);
  int len = strlen(s);
  int x = (len + 2) / 3;
  int y = len + 2 - 2 * x;
  for (int i = 0; i < x - 1; ++i) {
    printf("%c", s[i]);
    for (int k = 1; k < y - 1; ++k) printf(" ");
    printf("%c\n", s[len - i - 1]);
  }
  for (int i = 0; i < y; ++i) printf("%c", s[x + i - 1]);
}