#include <cstdio>
int ans[100005][2];
int arr[100005];
int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
    arr[i] += arr[i - 1];
  }
  int cnt = 0;
  for (int l = 0, r = 1, cost = 0x7fffffff;; ++l) {
    while (arr[r] - arr[l] < m and r <= n) ++r;
    if (arr[r] - arr[l] < m) break;
    while (l < r and arr[r] - arr[l + 1] >= m) ++l;
    if (cost > arr[r] - arr[l] - m) {
      cnt = 1;
      cost = arr[r] - arr[l] - m;
      ans[0][0] = l + 1;
      ans[0][1] = r;
    } else if (cost == arr[r] - arr[l] - m) {
      ans[cnt][0] = l + 1;
      ans[cnt++][1] = r;
    }
  }
  for (int i = 0; i < cnt; ++i) printf("%d-%d\n", ans[i][0], ans[i][1]);
}