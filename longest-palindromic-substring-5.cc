// 动态规划
//
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
// 难点在于如何实现沿对角线从左下方向右上方遍历，实现的方法是按照长度来，j-i ==
// L， L = 0,1,2,3...。
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
        if (j == i) {
          dp[i][j] = true;
        } else if (j == i + 1) {
          dp[i][j] = (s[i] == s[j]);
        } else if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1];
        }
        if (dp[i][j]) {
          longestPalindromLength = max(longestPalindromLength, j - i + 1);
          longestPalindromeIndex = i;
        }
      }
    }
    return s.substr(longestPalindromeIndex, longestPalindromLength);
  }
};

// 中心拓展法
//
// 判断一个字符串是否为回文串的方法为，从字符串中心向两边遍历，如果每个字符都相
// 等，则字符串为回文串。
//
// 长度为奇数的字符串回文中心为一个字符，长度为偶数的字符串回文中心为两个字符。
// 考虑这两种情况，对于长度为 N 的字符串，单字符回文中心有 N 个，双字符回文中心
// 有 N-1 个，分别从这 2*N-1 个回文中心向两边遍历，判断是否是回文串。
//
// 单字符回文中心实际上是双字符回文中心的特例，即回文中心的两个字符在同一个位置，
// 可以通过取模的技巧统一两种情况。
class Solution {
public:
  string longestPalindrome(string s) {
    int n = 2 * s.size() - 1;
    int cnt = 1;
    int beg = 0;
    for (int i = 0; i < n; ++i) {
      int left = i % s.size();
      int right = left + (i >= s.size());

      if (s[left] != s[right]) {
        continue;
      }

      while (left > 0 && right < s.size() - 1) {
        if (s[left - 1] != s[right + 1]) {
          break;
        }
        --left;
        ++right;
      }
      if (right - left + 1 > cnt) {
        beg = left;
        cnt = right - left + 1;
      }
    }
    return s.substr(beg, cnt);
  }
};
