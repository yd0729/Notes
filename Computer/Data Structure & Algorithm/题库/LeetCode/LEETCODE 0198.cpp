class Solution {
 public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    // 记录 dp[i+1] 和 dp[i+2]
    int dp_i_1 = 0, dp_i_2 = 0;
    // 记录 dp[i]
    int dp_i = 0;
    for (int i = n - 1; i >= 0; i--) {
      dp_i = max(dp_i_1, nums[i] + dp_i_2);
      dp_i_2 = dp_i_1;
      dp_i_1 = dp_i;
    }
    return dp_i;
  }
};