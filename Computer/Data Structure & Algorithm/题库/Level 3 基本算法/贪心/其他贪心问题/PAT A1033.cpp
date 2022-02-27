#include <algorithm>
#include <iostream>
using namespace std;
struct {
  double p, d;
} s[600];  // 站
int main() {
  int n;
  double cap, unit, can_go, fuel = 0, d, cost = 0;
  cin >> cap >> d >> unit >> n;
  can_go = cap * unit;
  for (int i = 0; i < n; ++i) cin >> s[i].p >> s[i].d;
  sort(s, s + n, [](auto &a, auto &b) { return a.d < b.d; });
  if (s[0].d != 0) {
    cout << "The maximum travel distance = 0.00";
    return 0;
  }
  s[n].d = d;
  for (int i = 0, nxt = 1; i < n; i = nxt, nxt = i + 1) {
    if (s[nxt].d > s[i].d + can_go) {
      printf("The maximum travel distance = %.2f", s[i].d + can_go);
      return 0;
    }
    for (int j = nxt; j <= n and s[j].d <= s[i].d + can_go; ++j) {
      if (s[j].p <= s[i].p) {
        nxt = j;
        break;
      }
      if (s[j].p < s[nxt].p) nxt = j;
    }
    if (s[nxt].p <= s[i].p) {  // 尽量少加油
      if ((fuel -= (s[nxt].d - s[i].d) / unit) < 0)
        cost += (-fuel) * s[i].p, fuel = 0;
    } else  // // 在当前站加满油
      cost += (cap - fuel) * s[i].p, fuel = cap - (s[nxt].d - s[i].d) / unit;
  }
  printf("%.2f", cost);
}