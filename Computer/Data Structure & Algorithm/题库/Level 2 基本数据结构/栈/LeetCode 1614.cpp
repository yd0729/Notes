//
//  main.cpp
//  LeetCode 1614
//
//  Created by 杨东 on 2022/1/7.
//  Copyright © 2022 PAT. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxDepth(string s) {
    int depth = 0, max_depth = 0;
    for (auto i : s) {
      if (i == '(') {
        ++depth;
        max_depth = max(depth, max_depth);
      } else if (i == ')') {
        --depth;
      }
    }
    return max_depth;
  }
};

string stringToString(string input) {
  assert(input.length() >= 2);
  string result;
  for (int i = 1; i < input.length() - 1; i++) {
    char currentChar = input[i];
    if (input[i] == '\\') {
      char nextChar = input[i + 1];
      switch (nextChar) {
        case '\"':
          result.push_back('\"');
          break;
        case '/':
          result.push_back('/');
          break;
        case '\\':
          result.push_back('\\');
          break;
        case 'b':
          result.push_back('\b');
          break;
        case 'f':
          result.push_back('\f');
          break;
        case 'r':
          result.push_back('\r');
          break;
        case 'n':
          result.push_back('\n');
          break;
        case 't':
          result.push_back('\t');
          break;
        default:
          break;
      }
      i++;
    } else {
      result.push_back(currentChar);
    }
  }
  return result;
}

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);

    int ret = Solution().maxDepth(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
