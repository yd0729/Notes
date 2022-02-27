#include <iostream>

using namespace std;

int main() {
  string str1, str2;
  cin >> str1 >> str2;

  int start = 0, len = str1.length();
  for (int i = 0; i < str1.length(); i++) {
    if (str1[i] == str2[0]) {
      int j = i, k = 0;
      for (; j < str1.length(); j++) {
        if (str1[j] == str2[k]) k++;
        if (k == str2.length()) break;
      }
      if (k == str2.length()) {
        if (j - i + 1 < len) {
          len = j - i + 1;
          start = i;
        }
      }
    }
  }

  cout << str1.substr(start, len);
}