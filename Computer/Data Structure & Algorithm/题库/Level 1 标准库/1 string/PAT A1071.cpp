#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  string s, t;
  map<string, int> mp;
  getline(cin, s);
  for (int i = 0; i < s.length(); ++i) {
    if (isalnum(s[i])) {
      s[i] = tolower(s[i]);
      t += s[i];
    }
    if (!isalnum(s[i]) or i == s.length() - 1) {
      if (t != "") ++mp[t];
      t = "";
    }
  }
  int max_cnt = 0;
  for (auto &e : mp) {
    if (e.second > max_cnt) {
      s = e.first;
      max_cnt = e.second;
    }
  }
  cout << s << " " << max_cnt;
}