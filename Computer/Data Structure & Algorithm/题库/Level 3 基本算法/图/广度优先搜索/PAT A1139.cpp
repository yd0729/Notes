#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, int> gender;
unordered_map<int, unordered_set<int>> graph;

int main() {
  string a, b;
  int n, m, o;

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;

    int ida = abs(stoi(a));
    int idb = abs(stoi(b));

    graph[ida].insert(idb);
    graph[idb].insert(ida);

    gender[ida] = a[0] == '-';
    gender[idb] = b[0] == '-';
  }

  cin >> o;
  for (int i = 0; i < o; ++i) {
    int a, b;
    set<pair<int, int>> ans;  // set 保证有序

    cin >> a >> b;

    a = abs(a);
    b = abs(b);

    for (auto &j : graph[a]) {
      if (j == a or j == b or gender[j] != gender[a]) continue;
      for (auto &k : graph[j]) {
        if (k == a or k == b or k == j or gender[k] != gender[b] or
            !graph[k].count(b))
          continue;
        ans.insert({j, k});
      }
    }

    cout << ans.size() << "\n";
    for (auto &e : ans)  // 注意：输出格式（然而题中并没有写）
      printf("%04d %04d\n", e.first, e.second);
  }
}