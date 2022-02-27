#include <cmath>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {  // 计算两个正数的最大公约数
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

string reduction(ll a, ll b) {  // 化简一个假分数
  string ret;
  bool neg = false;

  if (a == 0) return "0";

  if ((a ^ b) < 0) {  // 分数为负
    neg = true;
    ret += "(-";
    a = abs(a);
    b = abs(b);
  }

  if (b == 0) throw -1;  // clang-tidy

  int g = gcd(a, b);  // 约分
  a /= g;
  b /= g;

  ll k = a / b;
  if (k != 0) {
    ret += to_string(k);
    if ((a %= b) != 0) ret += " ";
  }

  if (a != 0) {
    ret += to_string(a) + "/" + to_string(b);
  }

  if (neg) ret += ")";
  return ret;
}

int main() {
  ll a1, b1, a2, b2;
  scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);

  string out1 = reduction(a1, b1), out2 = reduction(a2, b2);
  cout << out1 << " + " << out2 << " = "
       << reduction(a1 * b2 + a2 * b1, b1 * b2) << "\n";
  cout << out1 << " - " << out2 << " = "
       << reduction(a1 * b2 - a2 * b1, b1 * b2) << "\n";
  cout << out1 << " * " << out2 << " = " << reduction(a1 * a2, b1 * b2) << "\n";
  cout << out1 << " / " << out2 << " = "
       << (out2 != "0" ? reduction(a1 * b2, a2 * b1) : "Inf") << "\n";
}