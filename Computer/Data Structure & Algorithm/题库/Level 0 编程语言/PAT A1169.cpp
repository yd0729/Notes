#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool out[15];
int give[15][1005];  // [人][轮]
unordered_set<int> number;

int main() {
  int a, b, n, m;
  cin >> a >> b >> n >> m;

  number.insert(a);
  number.insert(b);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> give[i][j];
    }
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (out[j]) continue;

      bool kick = true;

      if (not number.count(give[j][i])) {
        for (auto &e : number) {
          if (number.count(e + give[j][i])) {
            kick = false;
            number.insert(give[j][i]);
            break;
          }
        }
      }

      if (kick) {
        // cout << "no " << give[j][i] << "\n";
        out[j] = true;
        printf("Round #%d: %d is out.\n", i, j);
      }
    }
  }

  vector<int> winner;
  for (int i = 1; i <= n; ++i) {
    if (not out[i]) winner.push_back(i);
  }

  if (winner.empty()) {
    printf("No winner.");
  } else {
    cout << "Winner(s):";
    for (auto &e : winner) {
      cout << " " << e;
    }
  }
}