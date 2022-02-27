#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  set<char> st;
  for (auto &i : s2) st.insert(i);
  for (auto &i : s1)
    if (!st.count(i)) cout << i;
}