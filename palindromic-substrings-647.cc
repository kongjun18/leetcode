// 动态规划或中心拓展法求回文串，直接套套路即可，详见 longest-palindromic-substring-5。
//
// dp[i][j] 表示子字符串 [i, j] 是否为回文串。
//
// dp[i][i+1] = (s[i] == s[i+1])
// dp[i][i] = true
// dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
class Solution {
public:
  int countSubstrings(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    int cnt = 0;
    for (int l = 0; l < s.size(); ++l) {
      int i = 0;
      int j = l;
      for (; j < s.size(); ++i, ++j) {
        if (j - i == 1) {
          dp[i][j] = (s[i] == s[j]);

        } else if (i == j) { // 将初始化操作放到循环中
          dp[i][j] = true;
        } else {
          dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
        }
        cnt += dp[i][j] == true;
      }
    }
    return cnt;
  }
};

// Better Dynamic Programming
// dp[i][j] = s[i] == s[j] && dp[i+1][j-1].
// dp[i+1][j-1] should be calculated first as d[i][j] depends on d[i+1][j-1]. As
// a result, we iterate bottom-up and left-to-right.
//
// if i > j, dp[i][j] should be true, so dp is initialized as true.
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 1));
        int cnt = n;

        for(int i = n-1;i >= 0;i--){
            for(int j = i+1;j < n;j++){
                f[i][j] = f[i+1][j-1] && s[i] == s[j];
                if(f[i][j] && i != j){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
// DFS + memorization
class Solution {
    private:
        bool dfs(string &s, int i , int j, vector<vector<int>> &memo) {
            if (memo[i][j] != -1) {
                return memo[i][j];
            }

            if (s[i] != s[j]) {
                memo[i][j] = false;
            } else {
                if (i+1 > j-1) {
                    memo[i][j] = true;
                } else {
                    memo[i][j] = dfs(s, i+1, j-1, memo);
                }
            }

            return memo[i][j];
        }
public:
    int countSubstrings(string s) {
        int ans=0;
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (dfs(s, i, j, memo)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
