#include <iostream>
#include <string>
using namespace std;
string arr[10] = {"zero", "one", "two",   "three", "four",
                  "five", "six", "seven", "eight", "nine"};
int main() {
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < s.length(); ++i) sum += s[i] - '0';
  string sum_str = to_string(sum);
  for (int i = 0; i < sum_str.length(); ++i)
    cout << arr[sum_str[i] - '0'] << (i + 1 == sum_str.length() ? "" : " ");
}
