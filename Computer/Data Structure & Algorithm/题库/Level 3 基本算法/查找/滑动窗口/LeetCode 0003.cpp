#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    auto map = vector<int>(256, -1);  // 字符 -> 最后出现的位置
    auto ans = 0, start = 0;          // 当前子串的开始位置

    for (int i = 0; i < s.length(); ++i) {
      if (map[s[i]] >= start) {  // 当前字符与之前字符重复
        start = map[s[i]] + 1;   // 从重复的下一个开始
      }

      // 当前的无重复字符串：[start, i]
      ans = max(ans, i - start + 1);
      map[s[i]] = i;
    }
    return ans;
  }
};