#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    unordered_map<int, int> m;
    for (int i = 0; i < pieces.size(); i++) {
      m[pieces[i][0]] = i;
    }
    int i = 0;
    while (i < arr.size()) {
      if (not m.count(arr[i])) {
        return false;
      }
      auto &piece = pieces[m[arr[i++]]];
      for (int j = 1;
           i < arr.size() and j < piece.size() and arr[i] == piece[j]; ++i, ++j)
        ;
    }
    return i == arr.size();
  }
};
