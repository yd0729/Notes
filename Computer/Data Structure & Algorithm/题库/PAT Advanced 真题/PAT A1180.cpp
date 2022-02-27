#include <algorithm>
#include <iostream>

using namespace std;

bool is_prime[100005];
int MAXP, n;

int main() {
  cin >> n >> MAXP;

  fill(is_prime + 2, is_prime + 1 + MAXP, true);
  for (int i = 2; i <= MAXP; i++) {
    for (int j = i * 2; j <= MAXP; j += i) {
      is_prime[j] = false;
    }
  }

  // for (int i = 0; i <= MAXP; i++) {
  //	if (is_prime[i])cout << i << " ";
  // }
  // cout << endl;

  if (n <= 1) {
    int max_prime = MAXP;
    while (not is_prime[max_prime]) max_prime--;
    cout << max_prime;
    return 0;
  }

  int max_prime, max_common_diff;
  bool found = false;
  for (max_common_diff = MAXP / (n - 1); max_common_diff >= 1;
       max_common_diff--) {
    for (max_prime = MAXP; max_prime >= 2;) {
      while (not is_prime[max_prime] && max_prime >= 2) max_prime--;
      if (max_prime >= 2) {
        found = true;
        for (int i = 0; i < n && found; i++) {
          if (max_prime - i * max_common_diff < 2 ||
              not is_prime[max_prime - i * max_common_diff]) {
            found = false;
          }
        }
      }
      if (found)
        goto out;
      else
        max_prime--;
    }
  }

out:
  if (found) {
    for (int i = n - 1; i >= 0; i--) {
      cout << max_prime - i * max_common_diff;
      if (i != 0) cout << " ";
    }
  } else {
    max_prime = MAXP;
    while (not is_prime[max_prime]) max_prime--;
    cout << max_prime;
  }
}
