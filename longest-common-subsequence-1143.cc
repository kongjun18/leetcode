// dp[i][j] 表示考虑从 0 开始、长度为 i 和 j 的两个数组部分，最长公共子序列。
//
// 考虑 dp[i][j]，有三种转移到 dp[i][j] 的路径，分别为 dp[i-1][j-1]、dp[i][j-1]
// 以及 dp[i-1][j-1]。
//
// dp[i-1][j-1]: 如果 text[i-1] == text[j-1]，则最长公共子序列长度加一。
//
// dp[i-1][j]：如果 text[i-1] != text[j-1]，则最长公共子序列长度不变；否则，必须
// 考虑 text[i-1] == text[j-1]，但恰好 text[j-1] 对应 text[i-2] 的情况，这种情况
// 下最长公共子序列长度不变。因此，这种情况有回到了 text[i-1] == text[j-1] 时
// dp[i-1][j-1] 的情况。

// dp[i][j-1]：同理。
//
// 递推公公式：
// if text1[i-1] == text[j-1] :
//     dp[i][j] = dp[i - 1][j - 1] + 1
// if text1[i-1] != text[j-1] :
//     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
//
// 初始化：
// 为了实现方便，dp[i][j] 的 i/j 表示长度，而非下标。如果 i/j 表示下标，必须处理
// dp[0][j] 和 dp[i][0] 的特殊情况。显然 dp[i][0] 和 dp[0][j] 均为 0。
//
// 遍历方向：
// 求 dp[i][j] 依赖 dp[i-1][j]、dp[i][j-1] 和 dp[i-1][j-1]。从 (1, 1) 开始，按行
// 遍历即可满足依赖关系。
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));

    for (int i = 1; i <= text1.size(); ++i) {
      for (int j = 1; j <= text2.size(); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[text1.size()][text2.size()];
  }
};
