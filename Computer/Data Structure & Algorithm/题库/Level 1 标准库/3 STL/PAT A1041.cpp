#include <cstdio>

int h[10005], a[100005];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    h[a[i]]++;
  }

  for (int i = 0; i < n; ++i) {
    if (h[a[i]] == 1) {
      printf("%d", a[i]);
      return 0;
    }
  }

  printf("None");
}