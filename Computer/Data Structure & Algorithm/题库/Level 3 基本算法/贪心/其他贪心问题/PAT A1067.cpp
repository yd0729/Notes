#include <algorithm>
#include <cstdio>
using namespace std;
int a[100005];
int main() {
  int n, cnt = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) {
    if (a[i] != i) {
      if (i > 0) cnt += 2;
      while (a[i] != i) {
        swap(a[i], a[a[i]]);
        ++cnt;
      }
    }
  }
  printf("%d", cnt);
}