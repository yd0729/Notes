class Solution {
 public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    // 添加两侧的虚拟气球
    vector<int> points(n + 2);
    points[0] = points[n + 1] = 1;
    for (int i = 1; i <= n; i++) {
      points[i] = nums[i - 1];
    }
    // base case 初始化为 0
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    // 状态转移， i 从下到上， j 从左到右
    for (int i = n; i >= 0; i--) {
      for (int j = i + 1; j < n + 2; j++) {
        for (int k = i + 1; k < j; k++) {
          dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] +
                                       points[i] * points[j] * points[k]);
        }
      }
    }
    return dp[0][n + 1];
  }
};