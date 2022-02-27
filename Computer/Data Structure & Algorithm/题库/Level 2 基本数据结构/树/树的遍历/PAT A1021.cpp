#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int max_h = 0;
bool visit[10010];
set<int> partial, ans;
vector<int> adj[10010];
void dfs(int u, int h) {
  visit[u] = true;
  if (h > max_h) {  // 如果获得了更大的树高
    partial.clear();
    partial.insert(u);
    max_h = h;
  } else if (h == max_h)
    partial.insert(u);
  for (int i = 0; i < adj[u].size(); ++i)
    if (!visit[adj[u][i]]) dfs(adj[u][i], h + 1);
}
int main() {
  int a, b, n, block = 0;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i)
    if (!visit[i]) {
      ++block;
      dfs(i, 1);
    }
  if (block > 1)
    printf("Error: %d components\n", block);
  else {
    ans = partial;
    fill_n(visit + 1, n, false);
    dfs(*partial.begin(), 1);
    for (auto &e : partial) ans.insert(e);
    for (auto &e : ans) printf("%d\n", e);
  }
}
