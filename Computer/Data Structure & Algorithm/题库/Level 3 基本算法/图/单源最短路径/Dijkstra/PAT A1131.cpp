#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 10005

array<int, MAX_N> dist;
array<bool, MAX_N> visit;
map<pair<int, int>, int> line;
vector<int> pre[MAX_N], graph[MAX_N];

void dijkstra(int start) {
  dist.fill(-1);
  visit.fill(false);

  using p = pair<int, int>;
  priority_queue<p, vector<p>, greater<p>> pq;

  dist[start] = 0;
  pre[start].clear();
  pq.push({0, start});

  while (!pq.empty()) {
    int u = pq.top().second, u_dist = pq.top().first;
    pq.pop();

    visit[u] = true;
    if (dist[u] < u_dist) continue;  // dist[u] != -1 是不需要的

    for (auto &v : graph[u]) {
      if (!visit[v] and (dist[v] == -1 or dist[v] > u_dist + 1)) {
        dist[v] = u_dist + 1;
        pq.push({dist[v], v});
        pre[v].clear();
        pre[v].push_back(u);
      } else if (dist[v] == u_dist + 1)
        pre[v].push_back(u);
    }
  }
}

int min_trans_cnt = MAX_N;
vector<int> path, tmp_path;

void trace(int x, int l, int trans_cnt) {
  if (trans_cnt > min_trans_cnt) return;

  if (pre[x].empty()) {
    if (min_trans_cnt > trans_cnt) {
      path = tmp_path;
      path.push_back(x);
      min_trans_cnt = trans_cnt;
    }
    return;
  }

  tmp_path.push_back(x);
  for (auto &v : pre[x]) {
    trace(v, line[{v, x}], trans_cnt + (line[{v, x}] != l));
  }
  tmp_path.pop_back();
}

int main() {
  int n, m, k, start, dest;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int stop_a;
    cin >> m >> stop_a;

    for (int j = 1, stop_b; j < m; ++j, stop_a = stop_b) {
      cin >> stop_b;

      line[{stop_a, stop_b}] = i;
      line[{stop_b, stop_a}] = i;

      graph[stop_a].push_back(stop_b);
      graph[stop_b].push_back(stop_a);
    }
  }

  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> start >> dest;

    dijkstra(start);

    min_trans_cnt = MAX_N;
    trace(dest, 0, 0);
    reverse(path.begin(), path.end());

    cout << path.size() - 1 << "\n";
    int to = path[0], from = path[0], l = line[{path[0], path[1]}];
    for (auto j = path.begin() + 1; j != path.end(); to = *(j++)) {
      if (l != line[{to, *j}]) {
        printf("Take Line#%d from %04d to %04d.\n", l, from, to);
        l = line[{to, *j}];
        from = to;
      }
    }
    printf("Take Line#%d from %04d to %04d.\n", l, from, to);
  }
}