#include <iostream>
#include <set>

using namespace std;

int cir[205];
set<int> graph[205];

int main() {
  int n, m, a, b, k, p;

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    graph[a].insert(b);
    graph[b].insert(a);
  }

  cin >> k;
  for (int i = 0; i < k; ++i) {
    bool is_visited[205] = {}, hc = false;

    cin >> p;
    for (int j = 0; j < p; ++j) cin >> cir[j];

    if (p == n + 1) {
      hc = cir[0] == cir[p - 1];

      for (int j = 0; hc and j < p - 1; ++j) {
        if (graph[cir[j]].count(cir[j + 1]) == 0) hc = false;
        if (is_visited[cir[j]])
          hc = false;
        else
          is_visited[cir[j]] = true;
      }
    }
    cout << (hc ? "YES\n" : "NO\n");
  }
}