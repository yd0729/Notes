#include <algorithm>
#include <iostream>

using namespace std;

int arr[100005];

int main() {
  int n, ans = 0;
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> arr[i];

  sort(arr, arr + n, greater<int>());
  while (ans < n and arr[ans] > ans + 1) ++ans;
  cout << ans;
}