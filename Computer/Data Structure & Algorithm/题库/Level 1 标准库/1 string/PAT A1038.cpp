#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string a[10005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n, [](string &x, string &y) { return x + y < y + x; });
  for (int i = 1; i < n; ++i) a[0] += a[i];
  auto p = a[0].find_first_not_of("0");
  cout << (p == string::npos ? "0" : a[0].substr(p));
}