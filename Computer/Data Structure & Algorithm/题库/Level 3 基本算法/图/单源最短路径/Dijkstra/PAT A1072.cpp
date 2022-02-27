#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using p = pair<int, int>;

const int INF = -1;
const int MAX_V = 1100;

string sp1, sp2;
int n, m, k, max_d, d, p1, p2;

vector<p> adj[MAX_V];
int dist[MAX_V];
bool visit[MAX_V];

void dijkstra(int s) {
  priority_queue<p, vector<p>, greater<p>> pq;

  for (int i = 0; i < MAX_V; ++i) {
    dist[i] = INF;
    visit[i] = false;
  }

  dist[s] = 0;
  pq.push({0, s});

  while (not pq.empty()) {
    int u = pq.top().second, w = pq.top().first;

    pq.pop();
    visit[u] = true;

    if (dist[u] < w) continue;

    for (auto &e : adj[u]) {
      int v = e.second, w = e.first;
      if (not visit[v] and (dist[v] == INF or dist[v] > dist[u] + w)) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
}

int id(string &s) {  // 把加油站和住宅统一编号
  if (s[0] == 'G')
    return stoi(s.substr(1)) + n;
  else
    return stoi(s);
}

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &max_d);
  for (int i = 0; i < k; ++i) {
    cin >> sp1 >> sp2 >> d;
    p1 = id(sp1);
    p2 = id(sp2);
    adj[p1].push_back({d, p2});
    adj[p2].push_back({d, p1});
  }
  int g_sum_d = INF, g_min_d = 0, s_id = INF;  // global
  for (int i = 1; i <= m; ++i) {
    dijkstra(n + i);  // 计算这个加油站到所有住宅的最短路径
    if (find_if_not(dist + 1, dist + 1 + n,
                    [&](int &d) { return d <= max_d; }) == dist + 1 + n) {
      int sum_d = dist[1];
      int min_d = dist[1];
      for_each(dist + 2, dist + 1 + n, [&](int &d) {
        sum_d += d;
        if (min_d > d) min_d = d;
      });
      if (g_min_d < min_d or (g_min_d == min_d and g_sum_d > sum_d)) {
        s_id = i;  // 更新最短距离最大的加油站位置
        g_sum_d = sum_d;
        g_min_d = min_d;
      }
    }
  }
  if (s_id != INF)
    printf("G%d\n%.1f %.1f", s_id, double(g_min_d), double(g_sum_d) / n);
  else
    printf("No Solution");
}