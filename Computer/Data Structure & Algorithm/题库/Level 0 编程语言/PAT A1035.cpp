#include <cstring>
#include <iostream>
using namespace std;
char account[1005][15], pass[1005][15];
bool modified[1005];
int main() {
  int n, cnt = 0;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s %s", account[i], pass[i]);
    int len = strlen(pass[i]);
    for (int j = 0; j < len; ++j) {
      switch (pass[i][j]) {
        case '1':
          pass[i][j] = '@';
          modified[i] = true;
          break;
        case '0':
          pass[i][j] = '%';
          modified[i] = true;
          break;
        case 'l':
          pass[i][j] = 'L';
          modified[i] = true;
          break;
        case 'O':
          pass[i][j] = 'o';
          modified[i] = true;
          break;
      }
    }
    if (modified[i]) ++cnt;
  }
  if (cnt) {
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i)
      if (modified[i]) printf("%s %s\n", account[i], pass[i]);
  } else if (n == 1)
    printf("There is %d account and no account is modified", n);
  else
    printf("There are %d accounts and no account is modified", n);
}
