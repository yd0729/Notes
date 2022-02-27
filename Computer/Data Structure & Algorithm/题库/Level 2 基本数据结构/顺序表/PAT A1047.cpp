#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> course[2505];

int id(string &name) {
  auto i = name.rbegin();
  int id = *i++ - '0';
  for (int base = 26; i != name.rend(); ++i, base *= 26)
    id += (*i - 'A') * base;
  return id;
}

string name(int id) {
  string name{char(id % 26 + '0')};
  for (int i = 0; i < 3; i++, id /= 26) name.append(1, (id / 26) % 26 + 'A');
  reverse(name.begin(), name.end());
  return name;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  int n, k, p, c;

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> s >> c;
    for (int j = 0; j < c; ++j) {
      cin >> p;
      course[p].push_back(id(s));
    }
  }

  for (int i = 1; i <= k; ++i) {
    cout << i << " " << course[i].size() << "\n";
    sort(course[i].begin(), course[i].end());
    for (auto &e : course[i]) cout << name(e) << "\n";
  }
}