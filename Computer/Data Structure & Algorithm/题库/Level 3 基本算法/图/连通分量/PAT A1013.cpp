#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define N 1111

vector<int> adj[N];
bool visit[N];
int del_v;

void dfs(int v) {
  visit[v] = true;
  for (int i = 0; i < adj[v].size(); ++i) {
    if (not visit[adj[v][i]] and adj[v][i] != del_v) {
      dfs(adj[v][i]);
    }
  }
}

int main() {
  int n, m, k, a, b;
  scanf("%d%d%d", &n, &m, &k);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int q = 0; q < k; ++q) {
    scanf("%d", &del_v);

    fill_n(visit, N, false);

    int block = 0;
    for (int i = 1; i <= n; ++i) {
      if (i != del_v and not visit[i]) {
        dfs(i);
        ++block;
      }
    }

    printf("%d\n", block - 1);
  }
}
