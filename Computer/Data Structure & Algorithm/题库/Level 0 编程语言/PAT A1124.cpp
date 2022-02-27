#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> follower, winner;

int main() {
  int m, n, s;
  cin >> m >> n >> s;

  for (int i = 0; i < m; ++i) {
    string str;
    cin >> str;
    follower.push_back(str);
  }

  if (s <= m) winner.push_back(follower[s - 1]);
  for (int j = 1, p = s; p < m; ++p) {
    if (j == n) {
      bool won = false;
      for (auto &e : winner)
        if (e == follower[p]) won = true;

      if (not won) {
        j = 1;
        winner.push_back(follower[p]);
      }
    } else
      ++j;
  }

  if (winner.empty())
    cout << "Keep going...\n";
  else
    for (auto &i : winner) cout << i << "\n";
}