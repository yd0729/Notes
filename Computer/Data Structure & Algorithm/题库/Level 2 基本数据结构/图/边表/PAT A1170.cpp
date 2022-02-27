#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int animal[505];
vector<pair<int, int>> edge;
unordered_set<int> species;

int main() {
  int n, r, k, a, b, m;
  cin >> n >> r >> k;

  for (int i = 0; i < r; ++i) {
    cin >> a >> b;
    edge.push_back({a, b});
  }

  cin >> m;
  for (int i = 0; i < m; ++i) {
    species.clear();

    for (int j = 1; j <= n; ++j) {
      cin >> animal[j];
      species.insert(animal[j]);
    }
    if (species.size() > k) {
      cout << "Error: Too many species.\n";
      continue;
    }
    if (species.size() < k) {
      cout << "Error: Too few species.\n";
      continue;
    }

    bool ok = true;
    for (auto &e : edge) {
      // cout << e.first << " " << e.second << "\n";
      // cout << animal[e.first] << animal[e.second] << "\n";
      if (animal[e.first] == animal[e.second]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}