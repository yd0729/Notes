#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
  int m, n, k;
  cin >> m >> n >> k;
  for (int i = 0; i < k; ++i) {
    stack<int> stk;
    vector<int> target(n);
    for (int j = 0; j < n; ++j) cin >> target[j];
    for (int j = 1, pos = 0; j <= n; ++j) {
      if (stk.size() == m) break;
      stk.push(j);
      while (not stk.empty() and stk.top() == target[pos]) {
        stk.pop();
        ++pos;
      }
    }
    if (stk.empty())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}