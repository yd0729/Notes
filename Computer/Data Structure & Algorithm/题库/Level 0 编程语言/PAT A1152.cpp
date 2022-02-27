#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool is_prime(int x) {
  bool ans = true;

  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      ans = false;
      break;
    }
  }

  return ans;
}

int main() {
  int l, k;
  string s;

  cin >> l >> k >> s;

  for (int i = 0; i + k <= l; ++i) {
    // int num;
    // sscanf(s.substr(i, k).c_str(), "%d", &num);

    if (is_prime(stoi(s.substr(i, k)))) {
      cout << s.substr(i, k);
      return 0;
    }
  }

  cout << "404";
}