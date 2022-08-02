// 何时最后一个石头的重量最小？
//
//     将石头分成总重量尽可能接近的两堆时，最后一个石头重量最小。
//
// 因此，解题的关键在于如何把一堆石头分成重量尽可能接近的两堆。最理想的情况是，
// 石头总重量为 sum，分成两堆总重量相同的石头。但是可能出现如 [2,2,5] 的情况，
// 无法分成重量相等的两堆。
//
// 可以将“把一堆石头分成两堆总重量尽可能相同的石头”转化为“从一堆总重量为 sum 的
// 石头中，挑出一堆最大重量为 sum/2 的石头。这个问题实际上是 01 背包的变形，背包
// 容量为 sum/2，物品重量为 stones[i]，并且价值也为 stones[i]。物品的价值是它自身
// 的重量，此 01 背包就是“从N 个石头中挑选石头到总重量为 sum/2 的背包中，最多能
// 多重的石头？
//
// 最理想的情况是恰好可以放入重 sum/2 的石头，即恰好分为重量相同的两堆；一种情
// 况是放入的石头重量不足 sum/2，此时放入的石头重量已经是最接近平分的重量，两堆
// 石头重量相减即可。
//
// 01 背包从物品遍历更加容易理解，dp[i][j] 表示考虑到物品 i，背包重量为 j 时，背
// 包能放入的最大价值（这里是石头重量）。
//
// 1. weight[i] > j
//    背包容量太小，无法放下物品 i，dp[i][j] = dp[i-1][j]。
// 2. weight[i] <= j
//    1. 不放入物品 i，dp[i][j] = dp[i-1][j]。
//    2. 放入物品 i，dp[i-1][j-weight[i]] + value[i]。
// dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])。
//
// 使用滚动数组降低空间复杂度，得到：dp[j]=max(dp[j], dp[j-weight[i]] + value[i])。
//
// 对于此题，递推公式为 dp[j]=max(dp[j], dp[j-stones[i]]+stones[i])。
//
// 注意，滚动数组只是降低空间复杂度的优化，其实还是根据二维数组遍历，要小心遍历
// 的方向，这里要从后往前遍历 j，避免在执行 dp[j]=max(dp[j], dp[j-stones[i]]+stones[i])
// 时，dp[j-stones[i]]已被修改（相当于二维数组中下一行的值）。
class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
    const auto sum = std::accumulate(stones.cbegin(), stones.cend(), 0);
    int n = sum / 2;
    vector<int> dp(n + 1);
    for (int i = 0; i < stones.size(); ++i) {
      for (int j = n; j >= stones[i]; --j) {
        dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
      }
    }
    return sum - dp.back() - dp.back();
  }
};
