#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int cnt[500];
int main() {
  int carry = 0;
  string s1, s2, s3;
  cin >> s1;
  s2 = s1;
  for (auto i = s2.rbegin(); i != s2.rend(); ++i) {
    int d = (*i - '0') * 2 + carry;
    *i = d % 10 + '0';
    carry = d / 10;
  }
  if (carry) s2.insert(s2.begin(), carry + '0');
  s3 = s2;
  sort(s1.begin(), s1.end());
  sort(s3.begin(), s3.end());
  cout << (s1 == s3 ? "Yes" : "No") << "\n" << s2;
}
