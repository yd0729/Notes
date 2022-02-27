#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool visit[1005];
vector<int> pre[1005], ans;

int main() {
  int n, m, a, b, k;

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    pre[b].push_back(a);
  }

  cin >> k;
  for (int i = 0; i < k; ++i) {
    bool flag = true;
    fill_n(visit, 1005, false);

    for (int j = 0; j < n; ++j) {
      cin >> a;
      if (flag) {
        visit[a] = true;
        for (auto &e : pre[a])
          if (!visit[e]) {
            ans.push_back(i);
            flag = false;
            break;
          }
      }
    }
  }

  for (auto i = ans.begin(); i != ans.end(); ++i)
    cout << *i << (i + 1 == ans.end() ? "\n" : " ");
}