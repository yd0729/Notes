class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    // base case: 一维 dp 数组全部初始化为 1
    vector<int> dp(n, 1);
    // 反向遍历保证正确的状态转移
    for (int i = n - 2; i >= 0; i--) {
      int pre = 0;
      for (int j = i + 1; j < n; j++) {
        int temp = dp[j];
        if (s[i] == s[j])
          dp[j] = pre + 2;
        else
          dp[j] = max(dp[j], dp[j - 1]);
        pre = temp;
      }
    }
    return dp[n - 1];
  }
};