class MonotonicQueue {
 private:
  deque<int> q;

 public:
  void push(int n) {
    // 将前面小于自己的都删除
    while (!q.empty() and q.back() < n) {
      q.pop_back();
    }
    q.push_back(n);
  }

  int max() {
    // 队头元素是最大的
    return q.front();
  }

  void pop(int n) {
    if (n == q.front()) {
      q.pop_front();
    }
  }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    MonotonicQueue window;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      if (i < k - 1) {
        // 先填满窗口的前 k - 1
        window.push(nums[i]);
      } else {
        // 窗口向前滑动，加入新数字
        window.push(nums[i]);
        // 记录当前窗口的最大值
        ans.push_back(window.max());
        // 移出旧数字
        window.pop(nums[i - k + 1]);
      }
    }
    return ans;
  }
};