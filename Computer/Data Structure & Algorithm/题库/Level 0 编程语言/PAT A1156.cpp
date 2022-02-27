#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int x) {
  if (x <= 1) return false;
  int sqr = sqrt(x);
  for (int i = 2; i <= sqr; ++i)
    if (x % i == 0) return false;
  return true;
}

int is_sexy(int x) {
  if (is_prime(x)) {
    if (is_prime(x - 6)) return x - 6;
    if (is_prime(x + 6)) return x + 6;
  }
  return -1;
}

int main() {
  int a, b;
  cin >> a;

  if ((b = is_sexy(a)) != -1)
    cout << "Yes\n" << b;
  else {
    while (is_sexy(++a) == -1)
      ;
    cout << "No\n" << a;
  }
}