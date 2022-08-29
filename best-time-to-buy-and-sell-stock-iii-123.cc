// 思路与 best-time-to-buy-and-sell-stock-with-cooldown-309 相同，best-time-to-buy-and-sell-stock-with-cooldown-309
// 引入冷静期导致原本 best-time-to-buy-and-sell-stock-ii-122 的两状态变为三状态，
// 这里变为四状态，道理仍然相同。
//
// best-time-to-buy-and-sell-stock-ii-122 的持有股票和不持有都拆分为“第一次”和“第二次”。
// 显然，第一次的递推公式不变。第二次持有股票，要么是之前就是第二次持有，要么是
// 第一次不持有股票后新买入。第二次不持有股票，要么是之前就是第二次不持有，要么是
// 第一次持有后出售股票。
//
// dp 数组含义：
// dp[i][0] 第一次交易买入后持有股票的利润
// dp[i][1] 第一次交易卖出后不持有股票的利润
// dp[i][2] 第二次交易买入后持有股票的利润
// dp[i][3] 第二次交易卖出后不持有股票的利润
//
// 递推公式：
// dp[i][0] = max(dp[i-1][0], - prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i])
// dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i])
// dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i])
//
// 初始化：
// dp[0][0] = -prices[0]
// dp[0][1] = 0
// dp[0][2] = -prices[0]
// dp[0][3] = 0
//
// dp[0][2] 初始值也是 -prices[0]，否则会导致 dp[1][2] = prices[0]。
// 实现中 prices 下标为 i-1 是因为 prices 下标从 0 开始。
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<vector<int>> dp(prices.size()+1, vector<int>(4));
    dp[0][0] = dp[0][2] = -prices[0];
    dp[0][1] = dp[0][3] = 0;
    for (int i = 1; i <= prices.size(); ++i) {
      dp[i][0] = max(dp[i-1][0], - prices[i-1]);
      dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i-1]);
      dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i-1]);
      dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i-1]);
    }
    return max(dp.back().at(1), dp.back().at(3));
  }
};
