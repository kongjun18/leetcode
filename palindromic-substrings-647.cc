// 动态规划或中心拓展法求回文串，直接套套路即可，详见 longest-palindromic-substring-5。
//
// dp[i][j] 表示子字符串 [i, j] 是否为回文串。
//
// dp[i][i+1] = (s[i] == s[i+1])
// dp[i][i] = true
// dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
class Solution {
public:
  int countSubstrings(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    int cnt = 0;
    for (int l = 0; l < s.size(); ++l) {
      int i = 0;
      int j = l;
      for (; j < s.size(); ++i, ++j) {
        if (j - i == 1) {
          dp[i][j] = (s[i] == s[j]);

        } else if (i == j) { // 将初始化操作放到循环中
          dp[i][j] = true;
        } else {
          dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
        }
        cnt += dp[i][j] == true;
      }
    }
    return cnt;
  }
};
