// 分割等和子集实际上是 01 背包问题的变形，可以转化为有 N 个物品，重量和价值均
// 为 w[i]，总重量为 W，每个物品最多取一次，放到容量为 W/2 的背包里，最多可以
// 放总重量为多少的物品？
//
// 物品重量和物品价值相等，那么 01 背包“一定重量的背包最多能放多大价值的物品”，
// 就变成了“一定重量的背包最多能放总重为多少的物品”。如果总重量恰好为 W/2，剩下
// 的那部分物品重量一定也为 W/w，可以分割为两个等和子集。
//
// dp[i][j] 表示考虑到 i 个物品，容量为 j 的背包，能够放下的物品价值（石头总重量）。
// weight[i] <= j:
//   dp[i][j] = max(dp[i-1][j-weight[i]] + value[i], dp[i-1][j])
// weight[i] > j:
//   dp[i][j] = dp[i-1][j]
//
// 通过递推公式发现，dp[i][j]的值值依赖于当前的 i/j 和上一行的值，因此只有当前
// 行和上一行的值是有用的，使用滚动数组压缩状态降低空间复杂度。
//
// 递推公式：
// weight[i] <= j 时，dp[j] = max(dp[j-weight[i]], dp[j])
//
// 初始状态：
// 即上面二维版本的第一行，只考虑 0 个物品，总价值一定为 0。
//
// 遍历方向
// 滚动数组相当于从上面二维版本的第二行开始，因此 i 从 1 开始。换个角度，从考虑
// i 个物品看，初始状态考虑 0 个物品，所以第一次遍历要从考虑 1 个物品开始。
//
// 从递推公式 dp[j] = max(dp[j-weight[i]], dp[j]) 可以看到，dp[j] 依赖上一次状
// 态中下标更小的 dp[j-weight[i]]，因此必须从后往前遍历。否则，在计算 dp[j] 前，
// dp[j-weight[i]] 可能被修改，更新为这一次的状态，dp[j] 递推公式错误使用“这一次
// 状态”。
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    if (nums.size() < 2) {
        return false;
    }
    int sum = accumulate(nums.cbegin(), nums.cend(), 0);
    if (sum & 1) {
      return false;
    }
    sum /= 2;
    vector<int> dp(sum + 1);
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = sum; j > 0; --j) {
        if (j >= nums[i]) {
          dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
        }
      }
    }
    return dp.back() == sum;
  }
};
