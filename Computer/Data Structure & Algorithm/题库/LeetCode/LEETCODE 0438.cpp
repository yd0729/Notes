class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, window;
    for (char c : p) need[c]++;

    int left = 0, right = 0;
    int valid = 0;

    vector<int> result;

    while (right < s.length()) {
      char c = s[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (need[c] == window[c]) {
          valid++;
        }
      }

      if (right - left == p.length()) {
        if (valid == need.size()) {
          result.push_back(left);
        }

        char d = s[left];
        left++;

        if (need.count(d)) {
          if (window[d] == need[d]) {
            valid--;
          }
          window[d]--;
        }
      }
    }

    return result;
  }
};