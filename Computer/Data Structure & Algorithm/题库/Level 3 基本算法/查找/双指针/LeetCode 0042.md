---
created: 2022-02-19T18:30:39 (UTC +08:00)
tags: []
source: https://leetcode-cn.com/problems/longest-palindromic-substring/
author:
---

# 42. 接雨水

给定  `n` 个非负整数表示每个宽度为 `1` 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

## 示例 1

![rainwatertrap](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png)

    输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
    输出：6
    解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

## 示例 2

    输入：height =[4,2,0,3,2,5\]
    输出：9

## 提示

- `n == height.length`
- `1 <= n <= 2 * 104`
- `0 <= height[i] <= 105`

## 题解

### 暴力算法

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int l_max = 0, r_max = 0;
            // 找右边最高的柱子
            for (int j = i; j < n; j++)
                r_max = max(r_max, height[j]);
            // 找左边最高的柱子
            for (int j = i; j >= 0; j--)
                l_max = max(l_max, height[j]);
            // 计算能够装的水
            ans += min(l_max, r_max) - height[i];
        }
        return ans;
    }
};
```

### 备忘录优化

预先把这两个数组算好，即可避免重复计算。

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        int ans = 0;
        // 数组充当备忘录
        vector<int> l_max(n), r_max(n);
        // 初始化 base case
        l_max[0] = height[0];
        r_max[n - 1] = height[n - 1];
        // 从左向右计算 l_max
        for (int i = 1; i < n; i++)
            l_max[i] = max(height[i], l_max[i - 1]);
        // 从右向左计算 r_max
        for (int i = n - 2; i >= 0; i--)
            r_max[i] = max(height[i], r_max[i + 1]);
        // 计算答案
        for (int i = 1; i < n - 1; i++)
            ans += min(l_max[i], r_max[i]) - height[i];
        return ans;
    }
};
```

### 双指针

不用备忘录提前计算，而是用双指针边走边算，节省下空间复杂度。

```cpp
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
```
