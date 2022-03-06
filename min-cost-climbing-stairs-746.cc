// SEE: climbing-stairs-70
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    // dp[n] = min{dp[n-1] + cost[n-1], dp[n-2] + cost[n-2]}; n > 2
    int r = 0;
    int p = 0; // dp[1] = 0
    int q = 0; // dp[0] = 0
    for (int i = 2; i <= cost.size(); ++i) {
      r = min(p + cost[i - 1], q + cost[i - 2]);
      q = p;
      p = r;
    }
    return r;
  }
};
