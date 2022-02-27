class Solution {
 public:
  int minInsertions(string s) {
    int n = s.length();
    vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; i--) {
      int pre = 0;  // dp[i + 1][j - 1]
      for (int j = i + 1; j < n; j++) {
        int temp = dp[j];
        if (s[i] == s[j]) {
          dp[j] = pre;  // dp[i][j] = dp[i + 1][j - 1];
        } else {
          dp[j] = min(dp[j], dp[j - 1]) +
                  1;  // dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
        pre = temp;
      }
    }

    return dp[n - 1];
  }
};