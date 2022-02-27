#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    int x = stoi(s);
    int a = stoi(s.substr(0, s.length() / 2));
    int b = stoi(s.substr(s.length() / 2));

    cout << (a * b == 0 or x % (a * b) ? "No" : "Yes") << "\n";
  }
}