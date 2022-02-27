class Solution {
 public:
  vector<int> dailyTemperatures(vector<int> &T) {
    vector<int> ans(T.size());
    stack<int> s;  // 这里放元素索引，而不是元素
    for (int i = T.size() - 1; i >= 0; i--) {
      while (!s.empty() and T[s.top()] <= T[i]) {
        s.pop();
      }
      ans[i] = s.empty() ? 0 : (s.top() - i);  // 得到索引间距
      s.push(i);                               // 加入索引，而不是元素
    }
    return ans;
  }
};