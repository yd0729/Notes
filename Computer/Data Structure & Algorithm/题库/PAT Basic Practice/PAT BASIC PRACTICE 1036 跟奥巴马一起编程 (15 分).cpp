#include <cstdio>

int main() {
  int col;
  char c;
  scanf("%d %c", &col, &c);
  for (int i = 0; i < (col + 1) / 2; i++) {
    if (i == 0) {
      for (int j = 0; j < col; j++) {
        printf("%c", c);
      }
      printf("\n");
    } else if (i == (col + 1) / 2 - 1) {
      for (int j = 0; j < col; j++) {
        printf("%c", c);
      }
    } else {
      for (int j = 0; j < col; j++) {
        if (j == 0)
          printf("%c", c);
        else if (j == col - 1)
          printf("%c\n", c);
        else
          printf(" ");
      }
    }
  }
  return 0;
}