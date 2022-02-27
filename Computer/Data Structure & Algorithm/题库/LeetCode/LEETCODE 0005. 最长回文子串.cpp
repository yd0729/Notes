class Solution {
 public:
  string longestPalindrome(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
      // 寻找长度为奇数的回文子串
      string s1 = palindrome(s, i, i);
      // 寻找长度为偶数的回文子串
      string s2 = palindrome(s, i, i + 1);
      // res = longest(res, s1, s2)
      res = res.size() > s1.size() ? res : s1;
      res = res.size() > s2.size() ? res : s2;
    }
    return res;
  }

  // 从 s[l] 和 s[r] 开始向两端扩散
  // 返回以 s[l] 和 s[r] 为中心的最长回文串
  string palindrome(string &s, int l, int r) {
    // 防止索引越界
    while (l >= 0 and r < s.size() and s[l] == s[r]) {
      l--;
      r++;
    }
    return s.substr(l + 1, r - l - 1);
  }
};