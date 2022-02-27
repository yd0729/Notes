#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int num;
  cin >> num;

  vector<int> arr(num);
  for (int i = 0; i < num; ++i) cin >> arr[i];
  sort(arr.begin(), arr.end(), greater<int>());

  int m = 0, n = 0;
  for (int i = 1; i * i <= num; ++i) {
    if (num % i == 0) {
      n = i;
      m = num / n;
    }
  }

  vector<vector<int>> spiral(m, vector<int>(n));
  for (int i = 0, j = 0; j < num; ++i) {
    for (int a = i; a < n - i and j < num; ++a) spiral[i][a] = arr[j++];
    for (int b = i + 1; b < m - i and j < num; ++b)
      spiral[b][n - i - 1] = arr[j++];
    for (int c = n - i - 2; c >= i and j < num; --c)
      spiral[m - i - 1][c] = arr[j++];
    for (int d = m - i - 2; d > i and j < num; --d) spiral[d][i] = arr[j++];
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << spiral[i][j];
      if (j != n - 1) cout << " ";
    }
    cout << "\n";
  }
}