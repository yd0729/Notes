#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, m, t, half;
  cin >> n >> m;
  half = m * n / 2;
  unordered_map<int, int> mp;
  for (int i = 0; i < n * m; ++i) {
    cin >> t;
    if (++mp[t] > half) {
      cout << t;
      return 0;
    }
  }
}