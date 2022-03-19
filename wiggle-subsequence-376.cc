// 题意
//
// 对于最长摆动序列，其末尾要么是递增的(称为递增序列)，要么是递减的（称为递减序列）。所以，对于考虑到
// 下标为 i 的数组，其最长摆动序列长度是递增序列和递减序列长度的最大值。
// 
// 整个数组可以看作一条折线波，计算最长的摆动序列，就是删除（跳过）一些
// 节点，找到波峰/波谷或波谷/波峰交替的波。

// 动态规划解法
//
// 考虑到下标 i 的最长递增序列为长度为 up[i]，最长递减序列为 down[i]。求最长摆
// 动序列为 max(up[i], down[i])。
//
// 对于 nums[i]，有三种情况：
// - nums[i] > nums[i-1]
// - nums[i] == nums[i-1]
// - nums[i] < nums[i-1]
//
// 对于 nums[i] > nums[i-1] 的情况：
// - 考虑到 i 的递增序列：
//     - 对于 i-1 的递增序列，nums[i] 没有创造波峰/波谷，up[i] = up[i-1] 不变。
//     - 对于 i-1 的递减序列，nums[i] 产生波峰，up[i] = down[i-1] + 1。
// - 考虑到 i 的递减序列：
//     - nums[i] > nums[i-1]，序列仍然递减，down[i] = down[i-1]。
//
// 对于 nums[i] == nums[i-1] 的情况：
// - 既没有创造波峰也没有创造波谷，所以 down[i] = down[i-1]，up[i] =
// up[i-1]。
//
// 对于 nums[i] < nums[i-1] 的情况：
// - 考虑到 i 的递减序列
//     - 对于 i-1 的递增序列，nums[i] 创造了波峰，down[i] = up[i] + 1。
//     - 对于 i-1 的递减序列，序列仍然递减，down[i] = down[i-1]。
// - 考虑到 i 的递增序列
//     - nums[i] < nums[i-1]，序列仍然递增,up[i] = up[i-1]。
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int up[nums.size()];
    int down[nums.size()];
    up[0] = down[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        up[i] = max(up[i - 1], down[i - 1] + 1);
        down[i] = down[i - 1];
      } else if (nums[i] < nums[i - 1]) {
        up[i] = up[i - 1];
        down[i] = max(down[i - 1], up[i - 1] + 1);
      } else {
        down[i] = down[i - 1];
        up[i] = up[i - 1];
      }
    }
    return nums.empty() ? 0 : max(up[nums.size() - 1], down[nums.size() - 1]);
  }
};

// 贪心法：跳过不满足“摆动”的节点，剩下的就是最大摆动序列。
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int pre_diff = 0;
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
      int curr_diff = nums[i] - nums[i - 1];
      if (curr_diff > 0 && pre_diff <= 0 || curr_diff < 0 && pre_diff >= 0) {
        pre_diff = curr_diff;
        ++count;
      }
    }
    return count;
  }
};
