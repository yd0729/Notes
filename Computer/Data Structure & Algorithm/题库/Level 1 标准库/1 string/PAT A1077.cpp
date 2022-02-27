#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.get();  // 吃掉回车！！
  string s, ans;
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    reverse(s.begin(), s.end());
    if (i == 0) {
      ans = s;
    } else {
      int min_len = min(s.length(), ans.length());
      for (int j = 0; j < min_len; ++j) {
        if (s[j] != ans[j]) {
          ans = ans.substr(0, j);
          break;
        }
      }
    }
  }
  reverse(ans.begin(), ans.end());
  if (ans.length() == 0)
    cout << "nai";
  else
    cout << ans;
}