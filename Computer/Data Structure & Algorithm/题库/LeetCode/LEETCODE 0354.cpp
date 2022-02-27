class Solution {
 public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [](vector<int> &a, vector<int> &b) {
           if (a[0] != b[0])
             return a[0] < b[0];
           else
             return a[1] > b[1];
         });
    vector<int> height(envelopes.size());
    for (int i = 0; i < envelopes.size(); i++) {
      height[i] = envelopes[i][1];
    }
    return lengthOfLIS(height);
  }

  int lengthOfLIS(vector<int> & nums) {
              // 每组牌的尾部
        vector<int> top(nums.size());
              // 牌组数初始化为 0
        int piles = 0;
        for (int i = 0; i < nums.size(); i++) {
                // 要处理的扑克牌
            int poker = nums[i];
                // 查找应放入的组（左边界）
            auto lb = lower_bound(top.begin(), top.begin() + piles, poker);
                // 没找到合适的组，新建一组
            if  (lb == top.begin() + piles)  piles++;
                // 把这张牌放到牌的堆顶
            *lb = poker;
          
}
        return piles;
    
  }
};