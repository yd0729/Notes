#include <iostream>
#include <vector>

using namespace std;

bool is_prime(long long x) {
  for (int i = 2; i * i < x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  long long N, tmp;
  cin >> N;
  if (N == 1) {
    cout << "1=1";
    return 0;
  }
  tmp = N;

  vector<pair<long long, int>> ans;
  for (int i = 2; i <= tmp; i++) {
    if (is_prime(i)) {
      if (tmp % i == 0) {
        tmp /= i;
        ans.emplace_back(i, 1);
        while (tmp % i == 0) {
          tmp /= i;
          ans.back().second++;
        }
      }
    }
  }
  cout << N << "=";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first;
    if (ans[i].second != 1) cout << "^" << ans[i].second;
    cout << (i == ans.size() - 1 ? "" : "*");
  }
}