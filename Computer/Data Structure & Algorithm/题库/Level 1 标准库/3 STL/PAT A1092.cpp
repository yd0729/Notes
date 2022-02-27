#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  int cnt = 0;
  unordered_map<char, int> mp1, mp2;

  for (auto &i : s1) mp1[i] += 1;
  for (auto &i : s2) mp2[i] += 1;
  for (auto &p : mp2) cnt += min(mp1[p.first], p.second);

  if (cnt == s2.length())
    cout << "Yes " << s1.length() - cnt;
  else
    cout << "No " << s2.length() - cnt;
}