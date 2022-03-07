// 注意递归公式的适用范围，不能认为下标不越界就万事大吉了。
//
// 本题中 dp[i] 表示有 i + 1 个房屋时，能盗窃的最大金额。使用“第 i 个”时，下标从
// 0 开始;使用“第 3 个”时，下标从 1 开始。
//
// 对于第 i 个房屋，要么偷要么不偷：
// - 偷：dp[i] = dp[i-2] + nums[i]
// - 不偷：dp[i] = dp[i-1]
// 因此，递推公式为 dp[i] = max(dp[i-2] + nums[i], dp[i-1])。
//
// 为了保证下标合法，i >= 2 && i >= 1。所以 dp[0] 和 dp[1] 单独计算，显然：
// - dp[0] = nums[0]
// - dp[1] = max(nums[0], nums[1])
//
// 当 i == 2 时，
// - 偷。dp[2] = dp[0] + nums[2]。
// - 不偷。dp[2] = dp[1] = max(nums[0], nums[1])。
// 如果不偷时 nums[2] < nums[0]，那么 max() 选中 dp[0] + nums[2]，结果正确。
// 对于更大的 i，结果也是正确的。
class Solution {
public:
  int rob(vector<int> &nums) {
    int houses = nums.size();
    if (houses == 0) {
      return 0;
    } else if (houses == 1) {
      return nums[0];
    } else if (houses == 2) {
      return max(nums[0], nums[1]);
    }
    int r = 0;
    int p = max(nums[0], nums[1]);
    int q = nums[0];
    for (int i = 2; i < nums.size(); ++i) {
      r = max(p, q + nums[i]);
      q = p;
      p = r;
    }
    return r;
  }
};
