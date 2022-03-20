// 动态规划
//
// 设 dp[i] 为考虑到 i 天的股票最低价，那么第 i 天卖出获取的最大利润为
// nums[i] - dp[i-1]，整个数组能够获取到的最大值是 max{nums[i] - dp[i-1]}, i 为
// 0~n。
//
// 对于 nums[i]，若 nums[i] < dp[i-1]，那么 dp[i] = nums[i]，否则不变（dp[i] =
// dp[i-1]）。
//
// 实现时不需要先计算每天卖出股票能获取的最大利润，遍历时一边记录最大值即可。
//
// 实际上，压缩 dp[] 数组后，动态规划的代码和贪心法就一样了。
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int dp[prices.size()];
    dp[0] = prices[0];
    int res = 0;
    for (int i = 1; i < prices.size(); ++i) {
      dp[i] = min(dp[i - 1], prices[i]);
      res = max(res, prices[i] - dp[i]);
    }
    return res;
  }
};

// 贪心法
//
// 局部最优：计算股票最低价买入到当前股票价格卖出的利润。
// 全局最优：随着时间的推移更新股票最低价，取利润最大值。
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min_price = INT_MAX;
    int profit = 0;
    for (auto price : prices) {
      if (price < min_price) {
        min_price = price;
      }
      profit = max(profit, price - min_price);
    }
    return profit;
  }
};
