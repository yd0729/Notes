#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> guest;
vector<int> single;
unordered_map<int, int> couple;

int main() {
  int n, a, b;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    couple[a] = b;
    couple[b] = a;
  }

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    guest.insert(a);
  }

  for (auto &i : guest) {
    if (couple.count(i) and guest.count(couple[i])) continue;
    single.push_back(i);
  }

  sort(single.begin(), single.end());

  cout << single.size() << "\n";
  for (auto i = single.begin(); i != single.end(); ++i)
    cout << setw(5) << setfill('0') << *i
         << (i + 1 == single.end() ? "\n" : " ");
}