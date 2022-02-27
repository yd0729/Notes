#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

struct Node {
  int v, w;
};

int graph[205][205], path[205];
unordered_set<int> visited;
set<pair<int, int>> visited_edge;

int main() {
  int n, m, u, v, w, k;

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    graph[u][v] = graph[v][u] = w;
  }

  cin >> k;
  int min_weight = 1e9, min_id = -1;
  for (int i = 1; i <= k; ++i) {
    // 读入路径并判断路径是否存在
    bool is_exist = true;
    int path_len, weight = 0;

    visited.clear();

    cin >> path_len;
    for (int j = 0; j < path_len; ++j) {
      cin >> path[j];
      if (is_exist) {
        if (j > 0) {
          if (graph[path[j]][path[j - 1]] == 0)
            is_exist = false;
          else
            weight += graph[path[j]][path[j - 1]];
        }
        visited.insert(path[j]);
      }
    }

    cout << "Path " << i << ": ";

    if (!is_exist) {
      cout << "NA (Not a TS cycle)\n";
      continue;
    }

    // 判断是否是经过了所有城市的环
    cout << weight << " ";
    if (!(visited.size() == n and path[0] == path[path_len - 1])) {
      cout << "(Not a TS cycle)\n";
      continue;
    }

    if (min_weight > weight) {
      min_weight = weight;
      min_id = i;
    }

    // 判断是否是简单环
    bool is_simple = true;

    visited_edge.clear();
    for (int j = 0; j < path_len - 1 and is_simple; ++j) {
      int u = path[j];
      int v = path[j + 1];
      if (u > v) swap(u, v);
      if (not visited_edge.count({u, v}))
        visited_edge.insert({u, v});
      else
        is_simple = false;
    }

    if (is_simple)
      cout << "(TS simple cycle)\n";
    else
      cout << "(TS cycle)\n";
  }
  cout << "Shortest Dist(" << min_id << ") = " << min_weight;
}