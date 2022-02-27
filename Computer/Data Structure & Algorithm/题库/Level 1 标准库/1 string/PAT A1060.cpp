#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void convert(string &a, int &k, int n) {
  k = 0;
  string s;
  int p = a.find_first_not_of('0');  //  去除前导 0
  if (p != string::npos) {           // 不是 0
    if (a[p] == '.') {               // < 1
      auto t = find_if_not(a.begin() + ++p, a.end(),
                           [](char &c) { return c == '0'; });
      if (t != a.end()) {
        k = a.begin() + p - t;
        s.append(a, t - a.begin(), n);
      }
    } else {  // > 1
      for (int point = 0, cnt = 0; p < a.length(); p++) {
        if (a[p] == '.')
          point = true;
        else {
          if (not point) k++;
          if (cnt++ < n) s.push_back(a[p]);
        }
      }
    }
  }
  if (s.length() < n) s.append(n - s.size(), '0');
  a = s;
}
void print_sci(string &s, int k) { cout << "0." << s << "*10^" << k; }
int main() {
  int k1, k2, n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  convert(s1, k1, n);
  convert(s2, k2, n);
  if (s1 == s2 and k1 == k2)
    cout << "YES ", print_sci(s1, k1), cout << '\n';
  else {
    cout << "NO ", print_sci(s1, k1);
    cout << " ", print_sci(s2, k2), cout << '\n';
  }
}