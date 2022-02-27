#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct st {
  string name;
  int gp, gm, gf, g;
};

vector<st> v;
unordered_map<string, int> name2index;

int main() {
  string s;
  int p, m, n, x;

  cin >> p >> m >> n;

  for (int i = 0; i < p; ++i) {
    cin >> s >> x;
    if (x >= 200) {  // 低于200的没资格
      name2index[s] = v.size();
      v.push_back(st{s, x, -1, -1, -1});
    }
  }

  for (int i = 0; i < m; ++i) {
    cin >> s >> x;
    if (name2index.count(s)) v[name2index[s]].gm = x;
  }

  for (int i = 0; i < n; ++i) {
    cin >> s >> x;
    if (name2index.count(s)) {
      int index = name2index[s];
      v[index].gf = x;
      v[index].g = v[index].gm > v[index].gf
                       ? round(v[index].gm * 0.4 + v[index].gf * 0.6)
                       : v[index].gf;
    }
  }

  sort(v.begin(), v.end(), [](st &a, st &b) {
    if (a.g != b.g)
      return a.g > b.g;
    else
      return a.name < b.name;
  });

  for (auto i = v.begin(); i != v.end() and i->g >= 60; ++i) {
    cout << i->name << " " << i->gp << " " << i->gm << " " << i->gf << " "
         << i->g << "\n";
  }
}