#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct {
  int w;
  vector<int> child;
  bool is_leaf() { return child.size() == 0; }
} node[105];
int n, m, s, t, u, c;
vector<int> p;
vector<vector<int>> path;
void dfs(int idx, int w) {
  w += node[idx].w;
  p.push_back(node[idx].w);
  if (node[idx].is_leaf() or w >= s) {
    if (node[idx].is_leaf() and w == s) path.push_back(p);
  }
  for (auto &e : node[idx].child) dfs(e, w);
  p.pop_back();
}
int main() {
  cin >> n >> m >> s;
  for (int i = 0; i < n; ++i) cin >> node[i].w;
  for (int i = 0; i < m; ++i) {
    cin >> t >> u;
    for (int j = 0; j < u; ++j) {
      cin >> c;
      node[t].child.push_back(c);
    }
  }
  dfs(0, 0);
  sort(path.begin(), path.end(), greater<vector<int>>());
  for (auto &p : path) {
    for (auto i = p.begin(); i != p.end(); i++)
      cout << *i << (i + 1 == p.end() ? "\n" : " ");
  }
}