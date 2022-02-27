class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    int sum = numbers[left] + numbers[right];
    while (sum != target) {
      if (sum > target) --right;
      if (sum < target) ++left;
      sum = numbers[left] + numbers[right];
    }
    return {left + 1, right + 1};
  }
};