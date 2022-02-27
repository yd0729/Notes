#include <iostream>
#include <map>

using namespace std;

bool is_prime(int x) {
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

map<int, int> rnk, check;

int main() {
  int n, c;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    rnk[c] = i + 1;
  }

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    printf("%04d: ", c);
    if (not rnk.count(c))
      cout << "Are you kidding?\n";
    else if (check[c])
      cout << "Checked\n";
    else if (rnk[c] == 1)
      cout << "Mystery Award\n";
    else if (is_prime(rnk[c]))
      cout << "Minion\n";
    else
      cout << "Chocolate\n";
    check[c] = 1;
  }
}