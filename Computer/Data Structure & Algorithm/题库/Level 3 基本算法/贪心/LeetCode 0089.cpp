//
//  main.cpp
//  LeetCode 89 格雷编码 cpp
//
//  Created by 杨东 on 2022/1/8.
//  Copyright © 2022 PAT. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> gray_code{0};
    for (int base = 1; n--; base *= 2) {
      for (int i = gray_code.size() - 1; i >= 0; --i) {
        gray_code.push_back(gray_code[i] + base);
      }
    }
    return gray_code;
  }
};

int stringToInteger(string input) { return stoi(input); }

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  while (getline(cin, line)) {
    int n = stringToInteger(line);

    vector<int> ret = Solution().grayCode(n);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
