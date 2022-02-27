#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_prime(int x) {
  if (x <= 1) return false;
  for (int i = 2, sqr = sqrt(x); i <= sqr; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int digit_sum(int x) {
  int sum = 0;

  string s = to_string(x);
  for (auto &e : s) sum += e - '0';

  return sum;
}

vector<array<int, 2>> record;

void dfs(int sum, int val, int number_of_digit_left, int sum_target) {
  if (number_of_digit_left == 0 and sum == sum_target) {
    int n = digit_sum(val + 1), g = gcd(sum, n);
    if (g > 2 and is_prime(g)) {
      record.push_back({n, val});
    }
  } else if (number_of_digit_left > 0) {
    for (int i = 0; i <= 9; ++i) {
      if (sum + i + number_of_digit_left * 9 - 9 >= sum_target and
          sum + i <= sum_target) {
        dfs(sum + i, val * 10 + i, number_of_digit_left - 1, sum_target);
      }
    }
  }
}

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  int n, k, m;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    record.clear();

    cin >> k >> m;

    cout << "Case " << i << "\n";

    for (int j = 1; j <= 9; ++j)  // 最高位不能是 0 ，保证是 K 位数
      dfs(j, j, k - 1, m);

    if (record.empty())
      cout << "No Solution\n";
    else {
      sort(record.begin(), record.end());
      for (int j = 0; j < record.size(); ++j)
        cout << record[j][0] << " " << record[j][1] << "\n";
    }
  }

  // fclose(stdin);
  // fclose(stdout);
}