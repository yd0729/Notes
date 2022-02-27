#include <iostream>
#include <string>

using namespace std;

int main() {
  int d, n;
  cin >> d >> n;

  string s = to_string(d);
  for (int i = 1; i < n; ++i) {
    string t;
    for (auto p = s.begin(); p != s.end();) {
      char c = *p;
      int cnt = 0;
      while (p != s.end() and *p == c) {
        ++p;
        ++cnt;
      }
      t.append(1, c);
      t.append(to_string(cnt));
    }
    s = t;
  }

  cout << s;
}