class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      // 计算出能凑成 sum 的那个数
      int tmp = target - nums[i];
      // 如果前边已经有了 tmp ，就说明找到了一组
      if (map.count(tmp)) return {i, map[tmp]};
      // 记录数值到下标的映射
      map[nums[i]] = i;
    }
    throw "No two sum solution";
  }
};