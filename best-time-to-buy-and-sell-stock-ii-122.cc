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
// 每日股票只有两种状态，买入或卖出，dp[i][0] 表示第 i 天为买入状态（第 i 天买
// 入或之前买入但未卖）的利润，dp[i][1] 表示第 i 天为卖出状态的利润。
//
// 若 i-1 日卖出股票
// - dp[i][0] = dp[i-1][1] - prices[i]
// - dp[i][1] = dp[i-1][1]
//
// 若 i-1 日买入股票
// - dp[i][0] = dp[i][0]
// - dp[i][1] = dp[i-1][1] + prices[i]
//
// 得到递推公式
// dp[i][0] = max(dp[i -1 ][0], dp[i - 1][1] - prices[i]);
// dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
//
// 考虑初始条件
// 第 0 天买入后的利润为 -prices[0]，卖出后的利润为 0。
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int dp[prices.size()][2];
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i -1 ][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[prices.size() - 1][1];
  }
};
