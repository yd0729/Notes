#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
using namespace std;
const int open = 8 * 60, close = 17 * 60;  // 时间
int len[1005], serve[1005];  // 顾客服务时长; 顾客被服务的时刻
queue<int> wait_q[25];       // 第 n + 1 个队列是黄线外的队列
int empty_t[25];             // 每个队列空的时间
int next(int j) {            // 窗口 j 能够服务下一个客户的时间
  if (wait_q[j].empty())
    return empty_t[j];
  else {
    int i = wait_q[j].front();
    return serve[i] + len[i];
  }
}
void add(int c, int j) {  // 将顾客 c 添加到窗口 j
  serve[c] = empty_t[j];
  if (empty_t[j] < close) {
    wait_q[j].push(c);
    empty_t[j] += len[c];
  }
}
int main() {
  int n, m, k, q, x;
  cin >> n >> m >> k >> q;
  fill_n(empty_t, n, open);
  fill_n(serve + 1, k, close);
  for (int i = 1; i <= k; ++i) {  // 前 m * n 个客户直接进入黄线内
    cin >> len[i];
    if (i <= m * n)
      add(i, (i - 1) % n);
    else
      wait_q[n].push(i);
  }
  for (
      ; not wait_q[n].empty();
      wait_q[n]
          .pop()) {  // 从第 n * m + 1
                     // 个客户开始，需要等待某个窗口处理完成后才能进入黄线前排队
    int j = 0;       // 最先完成服务的窗口
    int min_next = next(0);
    for (int i = 1; i < n; i++) {
      int next_i = next(i);
      if (next_i < min_next) {
        j = i;
        min_next = next_i;
      }
    }
    if (empty_t[j] >= close) break;
    if (not wait_q[j].empty()) wait_q[j].pop();
    add(wait_q[n].front(), j);
  }
  for (int i = 0; i < q; ++i) {
    cin >> x;
    if (serve[x] < close)
      printf("%02d:%02d\n", (serve[x] + len[x]) / 60, (serve[x] + len[x]) % 60);
    else
      cout << "Sorry\n";
  }
}
