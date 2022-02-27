#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define print_time(time) \
  printf("%02d:%02d:%02d", time / 3600, (time / 60) % 60, time % 60)
const int start = 8 * 3600, close = 21 * 3600;
enum { NORMAL, VIP };
struct Player {
  int arrive = close, play, serve = close, type;
} plys[10005];
int cnt[105], vip[105], free_t[105];  // 桌子
int main() {
  int n, k, m;
  scanf("%d", &n);  // 玩家
  for (int i = 0, h, m, s; i < n; ++i) {
    scanf("%d:%d:%d%d%d", &h, &m, &s, &plys[i].play, &plys[i].type);
    plys[i].arrive = h * 3600 + m * 60 + s;
    plys[i].play = min(120, plys[i].play) * 60;
  }
  sort(plys, plys + n, [](auto &a, auto &b) { return a.arrive < b.arrive; });
  scanf("%d%d", &k, &m);  // 桌子
  for (int i = 0, id; i < m; ++i) {
    scanf("%d", &id);
    vip[id] = true;
  }
  fill_n(free_t + 1, k, start);
  int front = 0;  // 服务
  while (true) {
    while (plys[front].serve != close)  // 判断是否还有玩家
      front++;
    if (plys[front].arrive >= close) break;
    int p, t = 0;  // 确定玩家和桌子
    bool has_q = none_of(free_t + 1, free_t + 1 + k, [&](int &x) {
      return x <= plys[front].arrive;
    });  // 判断目前是否存在等待队列
    if (has_q) {
      int min_free_t = close;  // 获得最先空出来的桌子
      for (int i = 1; i <= k; i++) {
        if (free_t[i] < min_free_t) {
          min_free_t = free_t[i];
          t = i;
        }
      }
      if (min_free_t == close) break;
      bool has_v = false;  // 判断是否有 VIP 在等待
      auto v = front;
      for (; plys[v].arrive <= min_free_t; v++) {
        if (plys[v].serve != close) continue;
        if (plys[v].type == VIP) {
          has_v = true;
          break;
        }
      }
      p = has_v and vip[t] ? v : front++;  // 只有第一种才可能插队
    } else {
      p = front++;
      t = find_if(free_t + 1, free_t + 1 + k,
                  [&](int &x) { return x <= plys[p].arrive; }) -
          free_t;
      if (plys[p].type == VIP)
        for (int i = 1; i <= k; i++)
          if (free_t[i] <= plys[p].arrive && vip[i]) {
            t = i;
            break;
          }
    }
    plys[p].serve = max(plys[p].arrive, free_t[t]);  // 更新
    free_t[t] = plys[p].serve + plys[p].play;
    cnt[t]++;
  }
  sort(plys, plys + n,
       [](Player &a, Player &b) { return a.serve < b.serve; });  // 输出
  for (int i = 0; plys[i].serve != close; ++i) {
    print_time(plys[i].arrive);
    printf(" ");
    print_time(plys[i].serve);
    int wait = plys[i].serve - plys[i].arrive;
    printf(" %d\n", wait / 60 + (wait % 60 >= 30));
  }
  for (int i = 1; i <= k; ++i) printf("%d%s", cnt[i], (i == k ? "" : " "));
}
