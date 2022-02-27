#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int v, d;
  Node() {}
  Node(int v, int d) : v(v), d(d) {}
};

vector<vector<Node>> adj;

void dijkstra(int start, vector<int> &dist) {
  fill(dist.begin(), dist.end(), -1);
  vector<bool> visited(dist.size());

  using p = pair<int, int>;
  priority_queue<p, vector<p>, greater<p>> pq;

  pq.push({0, start});
  dist[start] = 0;

  while (not pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist[u] != -1 && dist[u] < d) continue;

    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].v;
      int uv_weight = adj[u][i].d;
      if (not visited[v] && (dist[v] == -1 or dist[v] > dist[u] + uv_weight)) {
        dist[v] = dist[u] + uv_weight;
        pq.push({dist[v], v});
      }
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  adj.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int s1, s2, dist;
    cin >> s1 >> s2 >> dist;
    adj[s1].emplace_back(s2, dist);
    adj[s2].emplace_back(s1, dist);
  }

  int cur_spot = 0, total_cost = 0;
  vector<bool> visited(N + 1);
  vector<int> path{0}, dist(N + 1);
  while (true) {
    dijkstra(cur_spot, dist);
    int min_dist = -1, min_spot;
    for (int i = 1; i <= N; i++) {
      if (not visited[i] && dist[i] != -1 &&
          (min_dist == -1 or min_dist > dist[i])) {
        min_dist = dist[i];
        min_spot = i;
      }
    }
    if (min_dist == -1) break;
    path.push_back(min_spot);
    total_cost += min_dist;
    visited[min_spot] = true;
    cur_spot = min_spot;
  }
  for (auto i = path.begin(); i != path.end(); i++) {
    cout << *i;
    if (i + 1 != path.end()) {
      cout << " ";
    } else
      cout << "\n";
  }
  if (path.size() == N + 1) {
    cout << total_cost;
  } else {
    vector<int> impossible;
    for (int i = 1; i <= N; i++) {
      if (not visited[i]) impossible.push_back(i);
    }
    for (auto i = impossible.begin(); i != impossible.end(); i++) {
      cout << *i;
      if (i + 1 != impossible.end()) {
        cout << " ";
      } else
        cout << "\n";
    }
  }
}
