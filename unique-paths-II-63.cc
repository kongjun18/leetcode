// See: unique-paths-62
//
// 这道题在路上添加了障碍物，这会影响 dp[][] 的初始化。
// 如果第一行或第一列中出现障碍物，那么该行/列之后的格子都不可达！
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
