#include <algorithm>
#include <cstdio>

using namespace std;

long long a[100005];

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

  sort(a, a + n);

  int r = 0;
  for (int i = 0; i < n; ++i)
    r = max(r, int(upper_bound(a, a + n, a[i] * p) - (a + i)));
  printf("%d", r);
}