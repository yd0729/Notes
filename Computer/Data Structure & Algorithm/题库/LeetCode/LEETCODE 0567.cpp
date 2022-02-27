class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;
    for (char c : s1) need[c]++;

    int left = 0, right = 0;
    int vaild = 0;

    while (right < s2.length()) {
      char c = s2[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) {
          vaild++;
        }
      }

      while (right - left >= s1.length()) {  // 保证窗口的长度始终为 s1 的长度
        if (vaild == need.size()) {  // 这里就不用再判断子串的长度了
          return true;
        }

        char d = s2[left];
        left++;

        if (need.count(d)) {  // 保证不改变 need 的大小
          if (window[d] == need[d]) {
            vaild--;
          }
          window[d]--;
        }
      }
    }
    return false;
  }
};