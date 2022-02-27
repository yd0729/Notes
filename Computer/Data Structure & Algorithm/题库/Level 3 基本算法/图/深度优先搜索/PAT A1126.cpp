#include <iostream>
#include <vector>

using namespace std;

bool is_visited[505];
vector<int> adj[505];

void dfs(int x) {
  is_visited[x] = true;
  for (auto &e : adj[x])
    if (!is_visited[e]) dfs(e);
}

int main() {
  int n, m, x, y;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int odd = 0;
  for (int i = 1; i <= n; ++i) {
    cout << adj[i].size() << (i == n ? "\n" : " ");
    if (adj[i].size() % 2) ++odd;
  }

  dfs(1);

  for (int i = 1; i <= n; ++i)
    if (!is_visited[i]) {
      cout << "Non-Eulerian";
      return 0;
    }

  if (odd == 2)
    cout << "Semi-Eulerian";
  else if (odd == 0)
    cout << "Eulerian";
  else
    cout << "Non-Eulerian";
}