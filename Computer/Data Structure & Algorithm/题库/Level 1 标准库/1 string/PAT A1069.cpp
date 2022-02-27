#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  s.insert(0, 4 - s.length(), '0');
  do {
    string a = s, b = s;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    s = to_string(stoi(a) - stoi(b));
    s.insert(0, 4 - s.length(), '0');
    cout << a << " - " << b << " = " << s << '\n';
  } while (s != "6174" and s != "0000");
}