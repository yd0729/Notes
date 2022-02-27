#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2;
  for (auto &i : s1)
    if (s2.find(i) == string::npos and s3.find(toupper(i)) == string::npos)
      s3 += toupper(i);
  cout << s3;
}