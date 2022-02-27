#include <iostream>
#include <vector>

using namespace std;

int g[205][205];

int main() {
  int nv, ne, m, k;

  cin >> nv >> ne;
  for (int i = 0; i < ne; ++i) {
    int a, b;
    cin >> a >> b;
    g[a][b] = g[b][a] = 1;
  }

  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> k;
    vector<int> seq(k);
    for (int j = 0; j < k; ++j) cin >> seq[j];

    bool clique = true;
    for (int p = 0; p < k and clique; ++p)
      for (int q = p + 1; q < k and clique; ++q)
        if (g[seq[p]][seq[q]] == 0) clique = false;

    if (!clique) {
      cout << "Not a Clique\n";
      continue;
    }

    bool max_c = true;

    vector<bool> in(nv + 5);
    for (auto &e : seq) in[e] = true;

    for (int j = 1; j <= nv and max_c; ++j) {
      if (in[j]) continue;

      bool can_add = true;
      for (auto p = seq.begin(); p != seq.end() and can_add; ++p)
        if (g[*p][j] == 0) can_add = false;
        
      if (can_add) max_c = false;
    }

    if (max_c)
      cout << "Yes\n";
    else
      cout << "Not Maximal\n";
  }
}