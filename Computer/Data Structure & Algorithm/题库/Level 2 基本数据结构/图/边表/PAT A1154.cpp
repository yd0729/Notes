#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int color[10004];
unordered_set<int> color_set;
vector<pair<int, int>> edge;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edge.push_back({a, b});
  }

  int k;
  cin >> k;

  for (int i = 0; i < k; ++i) {
    color_set.clear();
    for (int j = 0; j < n; ++j) {
      cin >> color[j];
      color_set.insert(color[j]);
    }
    bool is_ok = true;
    for (auto &e : edge) {
      if (color[e.first] == color[e.second]) {
        is_ok = false;
        break;
      }
    }
    if (is_ok)
      cout << color_set.size() << "-coloring\n";
    else
      cout << "No\n";
  }
}