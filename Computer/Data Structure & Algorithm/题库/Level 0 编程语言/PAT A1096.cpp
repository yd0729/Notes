#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int first = n, len = 0;
  for (int l = 2, sqr = sqrt(n); l <= sqr; ++l) {
    for (int r = l, temp = r; n % temp == 0; temp *= ++r) {
      if (r - l + 1 > len) {
        first = l;
        len = r - l + 1;
      }
    }
  }

  if (len == 0) len = 1;  // len 为 0 ，说明这是一个质数
  cout << len << "\n";
  for (int i = 0; i < len; ++i) cout << first + i << (i == len - 1 ? "" : "*");
}