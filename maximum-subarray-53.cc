// 动态规划
//
// 数组 dp[i] 表示边界为 i 的最大连续子序列和。此时有两种情况：
//
// 1. dp[i] = dp[i-1] + nums[i]，即将 i 加入到连续子序列中。
// 2. dp[i] = nums[i]，从 i 开始新的子序列。
//
// 显然，dp[i] 应该取两者最大值，即 dp[i] = max(dp[i-1]+nums[i], nums[i])。
//
// 注意，dp[i] 表示边界为 i 的最大连续子序列和，而非整个数组的最大连续子序列和。
// 但整个数组的最大连续子序列和一定在 dp[i]，0<= i <nums.size() 取得。
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int res = nums[0];
    int dp[nums.size()];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      if (res < dp[i]) {
        res = dp[i];
      }
    }
    return res;
  }
};

// 贪心算法
//
// 何时连续子序列之和最大？
//
// 如果遇到了一个负数，相加后导致子序列值变小，但是之后可能遇到更大的正数，导致
// 子序列之和变大，因此无法将遇到负数作为找到连续子序列局部极大值的边界条件。
//
// 虽然无法将遇到负数作为找到连续子序列局部极大值的边界条件，但是当一个子序列之
// 和为负数时，这个子序列已经不再有和变大的可能了。因此，在此范围内的所有子序列
// 的和都可以找到，也就找到了此范围内的子序列之和最大值，每个范围都找一边就可以
// 得到整个数组的全局子序列之和最大值。
//
// 在此算法中，局部最优找的是和为负数的连续子序列的范围内的子序列之和最大值，找
// 所有的局部极值，其中最大的就是全局最优（整个数组的连续子序列之和最大值）。
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int sum = 0;
    int res = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      res = max(sum, res);
      if (sum < 0) {
        sum = 0;
      }
    }
    return res;
  }
};
