#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1, sum;
    while ((sum = numbers[left] + numbers[right]) != target) {
      if (sum > target) --right;
      if (sum < target) ++left;
    }
    return {left + 1, right + 1};
  }
};