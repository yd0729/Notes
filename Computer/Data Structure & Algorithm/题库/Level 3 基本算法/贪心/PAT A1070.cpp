#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
struct Mooncake {
  double amount, price;
} mooncake[1005];
int main() {
  int n;
  double d, r = 0;
  cin >> n >> d;
  for (int i = 0; i < n; ++i) cin >> mooncake[i].amount;
  for (int i = 0; i < n; ++i) cin >> mooncake[i].price;
  sort(mooncake, mooncake + n, [](Mooncake &a, Mooncake &b) {
    return a.price * b.amount > b.price * a.amount;
  });
  for (int i = 0; i < n; ++i) {
    if (d == 0) break;
    if (mooncake[i].amount < d) {
      d -= mooncake[i].amount;
      r += mooncake[i].price;
    } else {
      r += mooncake[i].price * d / mooncake[i].amount;
      break;
    }
  }
  cout << setiosflags(ios::fixed) << setprecision(2) << r;
}