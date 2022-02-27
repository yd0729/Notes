#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool is_palindromic(string &c) {
  for (int i = 0; i < c.length() / 2; ++i)
    if (c[i] != c[c.length() - i - 1]) return false;
  return true;
}

string add(const string &a) {
  string b = a;
  reverse(b.begin(), b.end());

  string c(a.length(), '0');

  int carry = 0;
  for (int i = a.length() - 1; i >= 0; --i) {
    int sum = a[i] + b[i] + carry - 2 * '0';
    c[i] = sum % 10 + '0';
    carry = sum / 10;
  }
  if (carry != 0) c.insert(c.begin(), '1');

  cout << a << " + " << b << " = " << c << "\n";
  return c;
}

int main() {
  string s;
  cin >> s;

  for (int cnt = 0; cnt < 10; ++cnt) {
    if (is_palindromic(s)) {
      cout << s << " is a palindromic number.";
      return 0;
    } else
      s = add(s);
  }

  cout << "Not found in 10 iterations.";
}