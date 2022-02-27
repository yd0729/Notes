class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    // dp[i][j]: s 的前 i 个是否与 p 的前 j 个匹配
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    // base case
    dp[0][0] = true;

    for (int i = 0; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (p[j - 1] != '*') {
          dp[i][j] =
              i > 0  // 不是 '*' ，所以 i = 0 肯定不行
              and dp[i - 1][j - 1]  // 只能是 '.' 或字符，所以之前的一定匹配才行
              and (s[i - 1] == p[j - 1]  // 字符
                   or p[j - 1] == '.');  // '.'
        } else {
          dp[i][j] =
              dp[i]
                [j - 2]  // 'x*' 匹配 0 个字符，按照规则，'*' 不能是第 1
                         // 个，所以这里可以不用判断 j >= 2 （'x*' 占 2 位）。
              or
              (i > 0  // 'x*' 匹配 0 个以上字符，所以 i = 0 肯定不行
               and
               dp[i - 1][j]  // 假如 'x*' 匹配 0 个字符，则 dp[i - 1][j] = true
               and (s[i - 1] == p[j - 2]   // 'x*'
                    or p[j - 2] == '.'));  // '.*'
        }

    return dp[m][n];  // 应该可以提前返回
  }
};