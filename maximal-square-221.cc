// Dynamic Programming
//
// dp[i][j] represents the side length of the square whoose right-bottom corner
// is matrix[i][j]. If matrix[i][j] is '1', dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]).
//
// Implementation Notes:
// - the element type of matrix is char instead of int.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] == '1';
            ans = max(ans, dp[i][0]);
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            dp[0][j] = matrix[0][j] == '1';
            ans = max(ans, dp[0][j]);
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                dp[i][j] = matrix[i][j] == '1' ? 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};

