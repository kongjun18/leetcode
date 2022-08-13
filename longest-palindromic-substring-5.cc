// 关键在于如何遍历二维 dp 数组。
//
// dp[i][j] = dp[i+1][j-1] 意味着计算 dp[i][j] 前要得到 dp[i+1][j-1] 的值，因此
// 必须斜边、从左下方到右上方遍历。
//
//\---------
// \      ^|
//  \    / |
//   \  /  |
//    \/   |
//     \   |
//      \  |
//       \ |
//        \|
//         -
//

// dp 数组含义
// dp[i][j] 表示下标 i 到 j 的字串是否为回文串。
//
// 递推公式
// dp[i][j] = (s[i] == s[j]) ? dp[i+1][j-1] : dp[i][j]
// dp[i][i+1] = (s[i]==s[i+1])
//
// 初始化
// dp[i][i] = true
//
// 遍历方向
// 计算dp[i][j] 依赖 dp[i+1][j+1]，因此要沿上三角矩阵对角线向右上方遍历。这里的
// 难点在于如何实现沿对角线从左下方向右上方遍历，实现的方法是按照长度来，j-i == L，
// L = 0,1,2,3...。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.size() < 2) {
      return s;
    }
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    int longestPalindromLength = INT_MIN;
    int longestPalindromeIndex = 0;
    for (int len = 0; len < s.size(); ++len) {
      int i = 0;
      int j = len;
      for (; j < s.size(); ++i, ++j) { //
#ifdef DEBUG
        cout << i << " " << j << endl;
        for (const auto &row : dp) {
          for (const auto &elem : row) {
            cout << elem << " ";
          }
          cout << endl;
        }
#endif
        if (j == i) {
          dp[i][j] = true;
        } else if (j == i + 1) {
          dp[i][j] = (s[i] == s[j]);
        } else if (s[i] == s[j]){
          dp[i][j] = dp[i + 1][j - 1];
        }
        if (dp[i][j]) {
          longestPalindromLength = max(longestPalindromLength, j - i + 1);
          longestPalindromeIndex = i;
        }
      }
    }
#ifdef DEBUG
    cout << longestPalindromeIndex << " " << longestPalindromLength << endl;
#endif
    return s.substr(longestPalindromeIndex, longestPalindromLength);
  }
};
