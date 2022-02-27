#include <iostream>
using namespace std;
char s[] = "0123456789ABC";
int main() {
  cout << '#';
  for (int i = 0, c; i < 3; ++i) {
    cin >> c;
    cout << s[c / 13] << s[c % 13];
  }
}
