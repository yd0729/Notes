class Solution {
 public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);  // 存放结果
    stack<int> s;
    // 假装这个数组长度翻倍了
    for (int i = 2 * n - 1; i >= 0; i--) {
      while (!s.empty() and s.top() <= nums[i % n]) s.pop();
      // 利用 % 求模防止索引越界
      res[i % n] = s.empty() ? -1 : s.top();
      s.push(nums[i % n]);
    }
    return res;
  }
};