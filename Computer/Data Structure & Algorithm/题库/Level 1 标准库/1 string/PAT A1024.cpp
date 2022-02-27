#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  int n, cnt = 0;
  cin >> s >> n;
  for (; cnt < n; ++cnt) {
    string t = s;
    reverse(t.begin(), t.end());
    if (t == s) break;
    int carry = 0;
    for (auto i = s.rbegin(), j = t.rbegin(); i != s.rend(); ++i, ++j) {
      int sum = *i + *j + carry - '0' * 2;
      *i = sum % 10 + '0';
      carry = sum / 10;
    }
    if (carry != 0) s.insert(s.begin(), carry + '0');
  }
  cout << s << "\n" << cnt;
}
