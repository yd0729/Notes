class Solution {
 public:
  vector<string> ans;

  void solve(int n, int left, int right, string &track) {
    if (left < n) {
      track.push_back('(');
      solve(n, left + 1, right, track);
      track.pop_back();
    }
    if (right < left) {
      track.push_back(')');
      solve(n, left, right + 1, track);
      track.pop_back();
    }
    if (left == n and right == n) {
      ans.push_back(track);
    }
  }

  vector<string> generateParenthesis(int n) {
    string track;
    solve(n, 0, 0, track);
    return ans;
  }
};