#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

bool computePre(double &result) {
  string s;

  if (!(cin >> s)) {
    result = 0;
    return true;
  }

  if (!isdigit(s[0]) and s.length() == 1) {  // 确保是运算符
    double a, b;
    if (!computePre(a) or !computePre(b)) return false;
    switch (s[0]) {
      case '+':
        result = a + b;
        return true;
      case '-':
        result = a - b;
        return true;
      case '*':
        result = a * b;
        return true;
      case '/':
        if (b == 0) return false;
        result = a / b;
        return true;
      default:
        return false;
    }
  } else {
    result = atof(s.c_str());
    return true;
  }
}

int main() {
  double result;
  if (computePre(result))
    cout << fixed << setprecision(1) << result;
  else
    cout << "ERROR";
}