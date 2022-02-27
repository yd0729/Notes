#include <iostream>

using namespace std;

int row[1005];
bool used[1005];

int main() {
  int k, n;
  cin >> k;

  while (k--) {
    cin >> n;

    fill_n(used, 1005, false);
    for (int i = 1; i <= n; ++i) cin >> row[i];

    bool ok = true;
    for (int i = 1; i <= n and ok; ++i) {
      if (!used[row[i]]) {  // 保证行唯一
        used[row[i]] = true;
        for (int pre = 1; pre < i; ++pre) {
          if (abs(pre - i) == abs(row[pre] - row[i])) {  // 保证对角线唯一
            ok = false;
            break;
          }
        }
      } else
        ok = false;
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }
}