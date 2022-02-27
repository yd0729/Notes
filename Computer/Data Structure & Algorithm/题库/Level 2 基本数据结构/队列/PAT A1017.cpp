#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define timestamp(h, m, s) (((h)*60 + (m)) * 60 + (s))
struct {
  int arrive, len;
} c[10005];
int main() {
  double wait = 0;
  int n, k, h, m, s, cnt = 0;
  scanf("%d %d\n", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d:%d:%d %d", &h, &m, &s, &c[i].len);
    c[i].arrive = timestamp(h, m, s);
    c[i].len = min(3600, c[i].len * 60);
  }
  sort(c, c + n, [](auto &a, auto &b) { return a.arrive < b.arrive; });
  priority_queue<int, vector<int>, greater<int>>
      pq;  // 用优先队列得到最先空闲的窗口
  for (int i = 0; i < k; ++i) pq.push(timestamp(8, 0, 0));
  for (int i = 0; i < n; ++i) {
    if (c[i].arrive > timestamp(17, 0, 0)) break;
    int next = pq.top();
    pq.pop();
    ++cnt;
    int serve = max(next, c[i].arrive);
    wait += serve - c[i].arrive;
    next = serve + c[i].len;
    pq.push(next);
  }
  if (cnt == 0)
    printf("0.0\n");
  else
    printf("%.1f", wait / cnt / 60);
}
