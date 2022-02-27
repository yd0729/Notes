#include <iostream>
#include <vector>

using namespace std;

int visit[10005];
vector<int> graph[10005];

int main() {
  int n, m, k, l, a, b, cnt;

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;

    graph[a].push_back(i);  // 与这个点关联的所有的边
    graph[b].push_back(i);
  }

  cin >> k;
  for (int i = 0; i < k; ++i) {
    cnt = 0;
    fill_n(visit, m, false);

    cin >> l;
    for (int j = 0; j < l; ++j) {
      cin >> a;
      for (auto &e : graph[a])
        if (!visit[e]) {
          ++cnt;
          visit[e] = true;
        }
    }

    cout << (cnt == m ? "Yes" : "No") << "\n";
  }
}