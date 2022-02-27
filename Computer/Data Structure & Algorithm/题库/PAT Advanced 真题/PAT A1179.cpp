#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<string> reactants;
vector<string> products;
map<string, vector<vector<string>>> equations;
map<string, int> solutions;

bool dfs(int x) {
  if (x == products.size()) {
    return true;
  }
  auto &product = products[x];
  for (int i = 0; i < equations[product].size(); i++) {
    bool ok = true;
    for (auto &reactant : equations[product][i]) {
      if (not reactants.count(reactant)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      for (auto &reactant : equations[product][i]) {
        reactants.erase(reactant);
      }

      if (dfs(x + 1)) {
        solutions[product] = i;
        return true;
      } else {
        for (auto &reactant : equations[product][i]) {
          reactants.insert(reactant);
        }
      }
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    reactants.insert(str);
  }

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    string str;
    cin >> str;
    products.push_back(str);
  }

  int K;
  cin >> K;

  for (int i = 0; i < K; i++) {
    string str;
    vector<string> left;
    while (cin >> str) {
      left.push_back(str);
      cin >> str;
      if (str == "->") break;
    }
    cin >> str;
    equations[str].push_back(left);
  }
  for (auto &reactant : reactants) {
    equations[reactant].push_back(vector<string>{reactant});
  }
  for (auto &product : products) {
    sort(equations[product].begin(), equations[product].end());
  }

  dfs(0);

  for (auto i = products.begin(); i != products.end(); i++) {
    auto &equation = equations[*i][solutions[*i]];
    for (auto j = equation.begin(); j != equation.end(); j++) {
      cout << *j;
      if (j + 1 != equation.end()) {
        cout << " + ";
      } else {
        cout << " -> ";
      }
    }
    cout << *i << "\n";
  }
}