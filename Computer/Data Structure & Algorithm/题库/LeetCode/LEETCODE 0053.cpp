class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int sum = nums[0], max_sum = sum;
    for (int i = 1; i < nums.size(); i++) {
      sum = max(nums[i], sum + nums[i]);
      if (max_sum < sum) max_sum = sum;
    }
    return max_sum;
  }
};