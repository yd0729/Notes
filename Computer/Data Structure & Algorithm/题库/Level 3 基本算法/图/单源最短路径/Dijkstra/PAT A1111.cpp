#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF -1
#define MAX_V 505
#define TIME 1
#define DIST 0

using p = pair<int, int>;

struct Node {
  int dist;                              // 与源点的距离
  bool visit;                            // 访问
  vector<int> pre;                       // 前驱
  vector<pair<int, array<int, 2>>> adj;  // 邻接的节点 {距离, 时间}
} graph[MAX_V];                          // 邻接表

int flag = 0;
array<int, 2> weight[MAX_V][MAX_V];  // 邻接矩阵表示的 {距离, 时间}

void dijkstra(int s) {
  for (int i = 0; i < MAX_V; ++i) {
    graph[i].dist = INF;
    graph[i].pre.clear();
    graph[i].visit = false;
  }

  priority_queue<p, vector<p>, greater<p>> pq;

  graph[s].dist = 0;
  pq.push({0, s});

  while (not pq.empty()) {
    int u_Id = pq.top().second;
    int u_dist = pq.top().first;
    auto &u = graph[u_Id];
    pq.pop();

    u.visit = true;

    if (u.dist < u_dist) continue;

    for (auto &e : u.adj) {
      int v_id = e.first;
      auto &v = graph[v_id];
      int uv = e.second[flag];

      if (not v.visit and (v.dist == INF or v.dist > u.dist + uv)) {
        v.dist = u.dist + uv;
        pq.push({v.dist, v_id});

        v.pre.clear();
        v.pre.push_back(u_Id);
      } else if (v.dist == u.dist + uv)
        v.pre.push_back(u_Id);
    }
  }
}

int min_2 = INF;  // 第 2 标准
vector<int> min_path[2], tmp_path;

void dfs(int end, int standard_2) {
  tmp_path.push_back(end);
  if (graph[end].pre.empty() and (min_2 == INF or min_2 > standard_2)) {
    min_2 = standard_2;
    min_path[flag] = tmp_path;
  }
  for (auto e : graph[end].pre)
    dfs(e, standard_2 + (flag == DIST ? weight[e][end][TIME] : 1));
  tmp_path.pop_back();
}

void print_path(vector<int> &path) {
  for (auto i = path.rbegin(); i != path.rend(); ++i) {
    cout << *i;
    if (i + 1 != path.rend())
      cout << " -> ";
    else
      cout << "\n";
  }
}

int main() {
  int n, m, v1, v2, one;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    array<int, 2> value;

    cin >> v1 >> v2 >> one >> value[0] >> value[1];

    graph[v1].adj.emplace_back(v2, value);
    weight[v1][v2] = value;
    if (not one) {
      graph[v2].adj.emplace_back(v1, value);
      weight[v2][v1] = value;
    }
  }

  int s, d;
  cin >> s >> d;

  array<int, 2> min_1;  // 第 1 标准

  for (flag = 0; flag < 2; ++flag) {
    dijkstra(s);
    min_2 = INF;
    dfs(d, 0);
    min_1[flag] = graph[d].dist;
  }

  if (min_path[DIST] == min_path[TIME]) {
    cout << "Distance = " << min_1[DIST] << "; Time = " << min_1[TIME] << ": ";
    print_path(min_path[DIST]);
  } else {
    cout << "Distance = " << min_1[DIST] << ": ";
    print_path(min_path[DIST]);
    cout << "Time = " << min_1[TIME] << ": ";
    print_path(min_path[TIME]);
  }
}