#include <iostream>
using namespace std;
char wtl[] = "WTL", bet[3];  // 如果要写长度的话应该是 4
int main() {
  double product = 1, odd;
  for (int i = 0; i < 3; ++i) {
    double max = 0;
    for (int j = 0; j < 3; ++j) {
      cin >> odd;
      if (max < odd) {
        max = odd;
        bet[i] = wtl[j];
      }
    }
    product *= max;
  }
  for (int i = 0; i < 3; ++i) cout << bet[i] << " ";
  printf("%.2f", (product * 0.65 - 1) * 2);
}
