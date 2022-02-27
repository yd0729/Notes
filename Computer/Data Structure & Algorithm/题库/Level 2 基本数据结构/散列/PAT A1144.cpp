#include <iostream>

using namespace std;

bool c[100005];

int main() {
  int n, x;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x > 0 and x <= 100000)  // 第一个缺少的正数一定是在这个范围之内的
      c[x] = true;
  }

  for (int i = 1; i <= 100000; ++i) {
    if (!c[i]) {
      cout << i;
      return 0;
    }
  }
  cout << 100001;
}