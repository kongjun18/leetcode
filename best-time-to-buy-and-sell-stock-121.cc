// 贪心法
//
// 低买高卖，也就是说把价格看成折线图，所有上升的折线之和就是最大利润。
// 昨天高，就应该低买高卖。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
                int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};

// 贪心
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

// 动态规划
//
// 题目要求求获取的最大利润，自然想到 dp[i] 表示第 i 天最大利润，但难以导出递推
// 公式。无法直接得到最大利润的递推公式，那就曲线救国，间接得到最大利润。
//
// 不考虑何时买入/卖出，而是考虑每一天的状态（手上有的钱），递推公式实际上就是
// 状态间的转移方程。
//
// dp[i][0]: 第 i 天持有股票的钱
// dp[i][1]: 第 i 天不持有股票的钱
//
// 第 i 天持有股票：
// - 前一天也持有股票，dp[i]][0] = dp[i-1][0]。
// - 前一天不持有股票，即第 i 天买入股票，由于只能买卖一次，因此买入时没有之前卖
//   出得到的利润，dp[i][0] = -prices[i]。
//
// 第 i 天不持有股票：
// - 前一天也不持有股票，dp[i][1] = dp[i-1][1]。
// - 前一天持有股票，即第 i 天卖出股票，dp[i][1] = dp[i-1][0] + prices[i]。
//
// 综上，递推公式如下：
// dp[i][0] = max(dp[i-1][0], -prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i-1][0], -prices[i]);
      dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);;
    }
    return dp[prices.size()-1][1];
  }
};

