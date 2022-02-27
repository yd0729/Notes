#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_V 505
#define INF -1
bool visited[MAX_V];
using p = pair<int, int>;
vector<p> adj[MAX_V];
int dist[MAX_V], path[MAX_V], sum[MAX_V], team[MAX_V];
void dijkstra(int start) {
  priority_queue<p, vector<p>, greater<p>> pq;
  pq.push({0, start});
  fill_n(dist, MAX_V, INF);
  dist[start] = 0;
  path[start] = 1;
  sum[start] = team[start];
  while (not pq.empty()) {
    auto top = pq.top();
    pq.pop();
    int &u = top.second;
    int &u_dist = top.first;
    visited[u] = true;
    if (dist[u] < u_dist)  // 1. 这里 dist[u] 不可能是 INF 2. dist[u] < u_dist
                           // 说明 u 的邻居都更新过了
      continue;
    for (auto &e : adj[u]) {
      int &v = e.second;
      int &uv = e.first;
      if (not visited[v] and (dist[v] == INF or dist[v] > dist[u] + uv)) {
        dist[v] = dist[u] + uv;
        pq.push({dist[v], v});
        path[v] = path[u];
        sum[v] = team[v] + sum[u];
      } else if (dist[v] == dist[u] + uv) {
        path[v] += path[u];
        if (sum[v] < team[v] + sum[u]) sum[v] = team[v] + sum[u];
      }
    }
  }
}
int main() {
  int n, m, c1, c2;
  cin >> n >> m >> c1 >> c2;
  for (int i = 0; i < n; ++i) cin >> team[i];
  for (int i = 0; i < m; ++i) {
    int a, b, l;
    cin >> a >> b >> l;
    adj[a].push_back({l, b});
    adj[b].push_back({l, a});
  }
  dijkstra(c1);
  cout << path[c2] << " " << sum[c2];
}