#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;

    int n = height.size();
    int left = 0, right = n - 1;
    int ans = 0;

    int l_max = height[0];
    int r_max = height[n - 1];

    while (left <= right) {
      l_max = max(l_max, height[left]);
      r_max = max(r_max, height[right]);

      // ans += min(l_max, r_max) - height[i]
      if (l_max < r_max) {
        ans += l_max - height[left];
        left++;
      } else {
        ans += r_max - height[right];
        right--;
      }
    }
    return ans;
  }
};