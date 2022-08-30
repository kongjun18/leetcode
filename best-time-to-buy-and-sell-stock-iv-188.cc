// best-time-to-buy-and-sell-stock-iv-188 在 best-time-to-buy-and-sell-stock-iii-123
// 的基础上从 2 次买卖拓展到 k 次买卖。通过 best-time-to-buy-and-sell-stock-iii-123，
// 可以发现 k 次买卖和 2 次买卖是一样的，第 k 次买卖的利润只取决与第 i-1 次买卖后
// 的利润和当天股票价钱。
//
// 将递推公式从 2 次改成 k 次即可，实现上就是把 k 次买卖写在循环中。
//
// best-time-to-buy-and-sell-stock-iii-123 递推公式：
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
// 这里为了容易循环，把上面的 dp 拆成 buy 和 sell。buy[i][j] 表示第 i 天第 k 次
// 买入后的利润，sell[i][j] 表示第 i 天第 k 次卖出的利润，i 从 1 开始，k 从 0 开始。
// 第一次买入的利润的公式和后续买入的公式不同，循环制需要单独处理。
class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    if (prices.size() < 2 || k < 1) {
      return 0;
    }
    vector<vector<int>> buy(prices.size() + 1, vector<int>(k));
    vector<vector<int>> sell(prices.size() + 1, vector<int>(k));
    for (int i = 0; i < k; ++i) {
      buy[0][i] = -prices[0];
      sell[0][i] = 0;
    }
    for (int i = 1; i <= prices.size(); ++i) {
      for (int j = 0; j < k; ++j) {
        if (j == 0) {
          buy[i][j] = max(buy[i - 1][j], -prices[i - 1]);
        } else {
          buy[i][j] = max(buy[i - 1][j], sell[i - 1][j - 1] - prices[i - 1]);
        }
        sell[i][j] = max(sell[i - 1][j], buy[i - 1][j] + prices[i - 1]);
      }
    }
    return *max_element(sell.back().cbegin(), sell.back().cend());
  }
};
