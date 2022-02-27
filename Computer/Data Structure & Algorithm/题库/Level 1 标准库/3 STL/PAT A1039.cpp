#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
string s;
int n, k, c, m;
unordered_map<string, vector<int>> mp;
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> c >> m;
    mp[s].reserve(m);
    for (int j = 0; j < m; ++j) {
      cin >> s;
      mp[s].push_back(c);
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (not is_sorted(mp[s].begin(), mp[s].end()))
      sort(mp[s].begin(), mp[s].end());
    cout << s << ' ' << mp[s].size();
    for (auto &e : mp[s]) cout << ' ' << e;
    cout << '\n';
  }
}