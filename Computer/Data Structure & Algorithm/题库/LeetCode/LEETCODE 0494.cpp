class Solution {
 public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    for (int n : nums) sum += n;
    // 这两种情况，不可能存在合法的子集划分
    if (sum < target or (sum + target) % 2 == 1) {
      return 0;
    }
    return subsets(nums, (sum + target) / 2);
  }

  int subsets(vector<int> &nums, int sum) {
    int n = nums.size();
    vector<int> dp(sum + 1, 0);
    // base case
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
      // j 要从后往前遍历
      for (int j = sum; j >= 0; j--) {
        // 状态转移方程
        if (j >= nums[i - 1]) {
          dp[j] = dp[j] + dp[j - nums[i - 1]];
        } else {
          dp[j] = dp[j];
        }
      }
    }
    return dp[sum];
  }
};