class Solution {
 public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> nextGreater;  // nums2 中全部元素的下一个更大的元素
    stack<int> s;
    for (int i = nums2.size() - 1; i >= 0; i--) {   // 倒着往栈里放
      while (!s.empty() and s.top() <= nums2[i]) {  // 判定个子高矮
        s.pop();  // 矮个子起开，反正也被挡着了
      }
      nextGreater[nums2[i]] =
          s.empty() ? -1 : s.top();  // 这个元素身后的第一个高个
      s.push(nums2[i]);  // 进队，接受之后的身高判定吧！
    }
    vector<int> ans;  // 从 nextGreater 中挑出 nums1 的作为答案
    for (int i : nums1) {
      ans.push_back(nextGreater[i]);
    }
    return ans;
  }
};