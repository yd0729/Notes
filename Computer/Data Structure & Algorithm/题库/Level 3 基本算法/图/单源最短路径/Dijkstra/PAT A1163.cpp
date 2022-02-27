#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

const int SIZE = 1005;

struct Node {
  int v, weight;

  bool operator<(Node &x) { return weight < x.weight; }
};

bool visited[SIZE];
vector<Node> adj[SIZE];
int nv, ne, k, dist[SIZE], target[SIZE];

bool dijkstra() {
  fill_n(dist + 1, nv, -1);
  dist[target[0]] = 0;
  fill_n(visited + 1, nv, false);

  for (int i = 0; i < nv; ++i) {
    int min_dist = -1;

    // 找出没有 visit 过的距离起点最小的所有的点
    unordered_set<int> shortest;
    for (int j = 1; j <= nv; ++j)
      if (!visited[j] and dist[j] != -1) {
        if (min_dist == -1 or min_dist > dist[j]) {
          min_dist = dist[j];
          shortest.clear();
          shortest.insert(j);
        } else if (min_dist == dist[j])
          shortest.insert(j);
      }

    // 判断给出的序列的第 i 位是否在 shortest 中
    int u = target[i];
    if (!shortest.count(u)) return false;

    // 松弛
    visited[u] = true;
    for (auto &e : adj[u]) {
      int v = e.v, uv = e.weight;
      if (!visited[v] and (dist[v] == -1 or dist[v] > dist[u] + uv))
        dist[v] = dist[u] + uv;
    }
  }

  return true;
}

int main() {
  cin >> nv >> ne;
  for (int i = 0; i < ne; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  cin >> k;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < nv; ++j) {
      cin >> target[j];
    }

    if (dijkstra())
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}