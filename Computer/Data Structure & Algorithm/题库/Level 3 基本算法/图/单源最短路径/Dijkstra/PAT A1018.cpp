#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_V 505
#define INF -1
using p = pair<int, int>;
bool visit[MAX_V];       // 访问标志
vector<int> pre[MAX_V];  // 前驱
vector<p> adj[MAX_V];    // 邻接表
int dist[MAX_V], bike[MAX_V];  // 从起点到每个点的最短距离 每个车站的车的数量
void dijkstra(int start) {
  priority_queue<p, vector<p>, greater<p>> pq;
  pq.push({0, start});
  fill_n(dist, MAX_V, INF);
  dist[start] = 0;
  pre[start].push_back(INF);
  while (not pq.empty()) {
    auto top = pq.top();
    pq.pop();
    int &u = top.second, &u_dist = top.first;
    visit[u] = true;
    if (dist[u] < u_dist) continue;
    for (auto &e : adj[u]) {
      int &v = e.second, &uv = e.first;
      if (not visit[v] and (dist[v] == INF or dist[v] > dist[u] + uv)) {
        dist[v] = dist[u] + uv;
        pq.push({dist[v], v});
        pre[v].clear();
        pre[v].push_back(u);
      } else if (dist[v] == dist[u] + uv) {
        pre[v].push_back(u);
      }
    }
  }
}
vector<int> path, tmp;
int min_s = INF, min_t = INF,
    perfect;  // 需要从节点0发出的车的数量 需要带回节点0的车的数量
              // 完美条件的数量
void dfs(int end) {
  if (end == INF) {  // 深搜到了一条完整的路径，开始计算花费
    int send = 0, take = 0;
    for (int i = tmp.size() - 2; i >= 0;
         --i) {  // 从经过的第一个**车站**开始到终点
      int p = tmp[i];
      if (bike[p] > perfect) {
        take += bike[p] - perfect;
      } else if (bike[p] < perfect) {
        if (take >= perfect - bike[p])
          take -= perfect - bike[p];
        else {
          send += perfect - bike[p] - take;
          take = 0;
        }
      }
    }
    if (min_s == INF || send < min_s or (send == min_s and take < min_t)) {
      path = tmp;
      reverse(path.begin(), path.end());
      min_s = send;
      min_t = take;
    }
    return;
  }
  tmp.push_back(end);
  for (auto e : pre[end]) dfs(e);
  tmp.pop_back();
}
int main() {
  int n, sp, m, a, b, t;  // 站台的数量 需要处理的车站的编号 路的数量
  cin >> perfect >> n >> sp >> m;
  perfect /= 2;
  for (int i = 1; i <= n; ++i) cin >> bike[i];
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> t;
    adj[a].push_back({t, b});
    adj[b].push_back({t, a});
  }
  dijkstra(0);
  dfs(sp);
  cout << min_s << " ";
  for (auto i = path.begin(); i != path.end(); ++i)
    cout << *i << (i + 1 != path.end() ? "->" : "");
  cout << " " << min_t;
}
