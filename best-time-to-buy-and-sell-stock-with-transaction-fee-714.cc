// 思路和 ./best-time-to-buy-and-sell-stock-ii-122 完全相同，只不过多了个手续费。
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int ans = INT_MIN;
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i <= prices.size(); ++i) {
      dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i-1]);
      dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i-1]-fee);
    }
    return dp.back().at(1);
  }
};
