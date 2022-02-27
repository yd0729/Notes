#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  if (s[0] == '-') cout << '-';

  int e = s.find("E");
  string base = s.substr(1, e - 1);
  int exp = stoi(s.substr(e + 1));

  if (exp >= 0) {
    cout << base[0];
    for (int i = 0; i + 2 < base.length() or i < exp; ++i) {
      if (i == exp) cout << '.';
      if (i + 2 < base.length())
        cout << base[i + 2];
      else
        cout << '0';
    }
  } else if (exp < 0) {
    cout << "0.";
    for (int i = 1; i < -exp; ++i) cout << '0';
    for (auto &e : base)
      if (e != '.') cout << e;
  }
}