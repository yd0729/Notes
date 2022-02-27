class Solution {
 public:
  int trap(vector<int> &height) {
    int sum = 0;
    stack<pair<int, int>> stk;

    for (int i = 0; i < height.size(); ++i) {
      int h = height[i];
      if (h == 0) continue;
      int current_height = 0;

      while (!stk.empty() and stk.top().second <= h) {
        auto t = stk.top();
        stk.pop();

        sum += (t.second - current_height) * (i - t.first - 1);
        current_height = t.second;
      }
      if (!stk.empty()) {
        auto t = stk.top();
        sum += (h - current_height) * (i - t.first - 1);
      }
      stk.push({i, h});
    }

    return sum;
  }
};