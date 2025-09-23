// 动态规划
//
// 第一想法是 dp[i][j] 表示 nums[i:j] 的最大字串和，这样有两个问题，一是复杂度
// 为 O(n^2)，而是状态迁移无法推进，到底要从 dp[i][i-1] 还是 dp[i-1][j] 还是dp[i-1][j-1]
// 迁移?
//
// 因此，找一个更好迁移的方案，dp[i] 表示 nums[0:i] 的最大子串和，则当 nums[0:i]
// 的最大字串和当前的 nums[i] 相邻时，dp[i] = dp[i-1] + nums[i]；如果不相邻，状态
// 就无法迁移了。
//
// 再去找更确定的更好迁移的状态，即 dp[i] 表示以 nums[i] 为结尾的最大字串和，这样
// 动态规划状态可以轻松迁移。
//
// 对于 dp[i] 有两种情况：
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
