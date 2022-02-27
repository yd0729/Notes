#include <iostream>
#include <string>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  string s = to_string(a + b);
  for (int i = 0, len = int(s.length()); i < len; i++) {
    cout << s[i];
    if (s[i] == '-' or i == len - 1)  // 负号或者最后一位不用加逗号
      continue;
    if ((i + 1) % 3 == len % 3)  // i + 1 表示第几个位置
      cout << ",";
  }
}