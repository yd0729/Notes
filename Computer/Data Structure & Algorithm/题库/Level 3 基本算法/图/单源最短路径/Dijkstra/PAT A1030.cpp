#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 505;
const int INF = -1;
bool visit[MAX_N];
vector<array<int, 3>> adj[MAX_N];
int cost[2][MAX_N], pre[MAX_N];
void dijkstra(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, s});
  fill_n(cost[0], MAX_N, INF);
  cost[0][s] = cost[1][s] = 0;
  pre[s] = INF;
  while (not pq.empty()) {
    auto top = pq.top();
    pq.pop();
    int &u = top.second, u_dist = top.first;
    visit[u] = true;
    if (cost[0][u] < u_dist) continue;
    for (auto &e : adj[u]) {
      int &v = e[2], &uv_w = e[0], &uv_c = e[1];
      if (not visit[v] and
          (cost[0][v] == INF or cost[0][v] > cost[0][u] + uv_w)) {
        pre[v] = u;
        cost[0][v] = cost[0][u] + uv_w;
        cost[1][v] = cost[1][u] + uv_c;
        pq.push({cost[0][v], v});
      } else if (cost[0][v] == cost[0][u] + uv_w and
                 cost[1][v] > cost[1][u] + uv_c) {
        pre[v] = u;
        cost[1][v] = cost[1][u] + uv_c;
      }
    }
  }
}
void print_path(int d) {
  if (pre[d] != INF) print_path(pre[d]);
  cout << (pre[d] == INF ? "" : " ") << d;
}
int main() {
  int n, m, s, d, c1, c2, w, c;
  cin >> n >> m >> s >> d;
  for (int i = 0; i < m; ++i) {
    cin >> c1 >> c2 >> w >> c;
    adj[c1].push_back({w, c, c2});
    adj[c2].push_back({w, c, c1});
  }
  dijkstra(s);
  print_path(d);
  cout << " " << cost[0][d] << " " << cost[1][d];
}