// 这题是 best-time-to-buy-and-sell-stock-ii-122 的姊妹题，非常值得研究。
// 添加冷静期后，不可以卖出后立刻买入，这导致 best-time-to-buy-and-sell-stock-ii-122
// 的递归公式失效。
//
// 尽管引入冷静期机制导致 best-time-to-buy-and-sell-stock-ii-122 递推公式实现，但
// 思路仍然不变，即递归公式在一定条件下仍然是成立的。直觉上需要判断下是否在冷静期，
// 如果在冷静期就不买入股票，否则可以买入。
//
// 问题在于如何实现判断的逻辑。实际上，递推公式是一个不变量，描述的是状态的转移，
// 递推公式也就是状态转移方程，动态规划的入手点在于状态间的递推关系（不变量）。
// best-time-to-buy-and-sell-stock-ii-122 中有两个状态，持有股票和未持有股票，假如
// 冷静期后只需要将未持有股票拆分为未持有股票且在冷静期、未持有股票且在冷静期两
// 个状态即可。买入状态只能由买入状态和未持有股票且在冷静期两个状态转移到。
//
// dp[i][0] 代表第 i 天为买入状态下的利润，dp[i][1] 代表第 i 天为卖出且不在冷静期
// 的利润，dp[i][2] 为第 i 天为卖出且在冷静期的利润。
//
// 递推公式如下
// dp[i][0] = max(dp[i - 1][0], dp[i][1] - prices[i]);
// dp[i][1] = max(dp[i - 1][1], dp[i][2]);
// dp[i][2] = dp[i - 1][0] + prices[i];
//
// 初始值
// dp[0][0] = -prices[0];
// dp[0][1] = 0;
// dp[0][2] = 0;
//
// 注意，实现中递推公式不一样是因为 prices 数组下标从 0 开始。
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<vector<int>> dp(prices.size() + 1, vector<int>(3));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i <= prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
      dp[i][2] = dp[i - 1][0] + prices[i - 1];
    }
    return max(dp.back().at(1), dp.back().at(2));
  }
};
