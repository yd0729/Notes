#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visit[1005];
int level[1005];
vector<int> follower[1005];

int bfs(int x, int max_l, int n) {
  fill_n(visit + 1, n, false);
  int cnt = 0;
  queue<int> q;
  q.push(x);
  visit[x] = true;
  level[x] = 0;
  while (not q.empty()) {
    int f = q.front();
    q.pop();
    if (level[f] < max_l) {
      for (auto &e : follower[f]) {
        if (not visit[e]) {
          ++cnt;
          level[e] = level[f] + 1;
          visit[e] = true;
          q.push(e);
        }
      }
    }
  }
  return cnt;
}

int main() {
  int n, l, m, c, q, k;
  cin >> n >> l;
  for (int i = 1; i <= n; ++i) {
    cin >> m;
    for (int j = 0; j < m; ++j) {
      cin >> c;
      follower[c].push_back(i);
    }
  }
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> q;
    cout << bfs(q, l, n) << "\n";
  }
}