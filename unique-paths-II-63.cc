// See: unique-paths-62
//
// 对于任意一个位置，有 4 种可能：
// 1. 可以从上面和左边到达
// 2. 只可以从上面到达
// 3. 只可以中左边到达
// 4. 位置是石头，不可到达
//
// 从 dp 公式可以看到，初始化是从左往右，从上往下。
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      if (obstacleGrid[0][i]) {
        break;
      }
      dp[0][i] = 1;
    }
    for (int i = 0; i < m; ++i) {
      if (obstacleGrid[i][0]) {
        break;
      }
      dp[i][0] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j]) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
