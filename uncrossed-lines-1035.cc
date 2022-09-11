// intel 笔试编程第一题
//
// 暴力法递归穷举所有情况，求最大值。
// 以 [nums1_start, nums1_end) 为主，在 [nums2_start, nums2_end) 中找等于
// *nums1_start 的数，有三种情况：
// - 未查找到：[nums1_start+1, nums1_end) 在 [nums2_start, nums2_end) 中查找。
// - 查找到：
//     - nums1_start 上的元素和 nums2 中第一个相等元素连线在“目标”情况（线最多）
//       中，那么在 nums2 查找到的元素后面继续搜索。
//     - 这条线不再“目标”情况中，“删除”这条线，按 [nums1_start+1, nums1_end) 在
//       [nums2_start, nums2_end) 继续搜索。
//
// 这个办法应该是队的，但是复杂度很高，程序超时。
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    dfs(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), 0);
    return max_count;
  }

private:
  int max_count{0};
  template <typename Iter>
  void dfs(Iter nums1_start, Iter nums1_end, Iter nums2_start, Iter nums2_end,
           int count) {
    if (distance(nums1_start, nums1_end) <= 0) {
      max_count = max(max_count, count);
      return;
    }
    auto nums2_pos = find(nums2_start, nums2_end, *nums1_start);
    if (nums2_pos < nums2_end) {
      dfs(nums1_start + 1, nums1_end, nums2_pos + 1, nums2_end, count + 1);
    }
    dfs(nums1_start + 1, nums1_end, nums2_start, nums2_end, count);
  }
};

// 最长公共子序列
//
// 最长公共子序列连线，得到最多的不相交的线。因此，这道题实际上是在问两数组最长
// 公共子序列有多长。拷贝 longest-common-subsequence-1143 的代码即可。
class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));

    for (int i = 1; i <= nums1.size(); ++i) {
      for (int j = 1; j <= nums2.size(); ++j) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[nums1.size()][nums2.size()];
  }
};
