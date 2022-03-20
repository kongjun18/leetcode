// 贪心法
//
// 想像自己是一个贪婪且短视的股民，只看今明两天的股价，只要明天涨价就今
// 日买明日卖，看到股票亏损则不买卖，等到涨价再买卖。
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int res = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if ((prices[i] - prices[i - 1]) > 0) {
        res += prices[i] - prices[i - 1];
      }
    }
    return res;
  }
};

// 动态规划
//
// 每日股票只有两种状态，买入或卖出，所以股民手中的钱要么是买入股票后剩
// 下的钱（dp[i][0]），要么是卖出股票赚取利润后的钱（dp[i][1]）。最大利
// 润为最后一天的两种可能的钱的最大值。
//
// 若 i-1 日卖出股票
// - dp[i][0] = dp[i-1][1] - prices[i]
// - dp[i][1] = dp[i-1][1]
//
// 若 i-1 日买入股票
// - dp[i][0] = dp[i][0]
// - dp[i][1] = dp[i-1][1] - prices[i]
//
// 综上，dp[i][0] = max(dp[i-1][1] - prices[i], dp[i][0])
//       dp[i][1] = max(dp[i-1][1], dp[i-1][1] - prices[i])
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int dp[prices.size()][2];
    dp[0][0] = 0;
    dp[0][1] = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i][0]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] - prices[i]);
    }
    return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
  }
};
