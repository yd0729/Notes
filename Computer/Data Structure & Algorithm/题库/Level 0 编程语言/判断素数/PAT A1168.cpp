#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool is_prime(int x) {
  if (x <= 1) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (int i = 3; i <= sqrt(x); i += 2) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;

  bool all_prime = true;

  for (int i = 0; i < s.length(); ++i) {
    string sub = s.substr(i);
    bool prime = is_prime(stoi(sub));
    cout << sub << " " << (prime ? "Yes\n" : "No\n");
    if (not prime) all_prime = false;
  }

  if (all_prime) cout << "All Prime!";
}
