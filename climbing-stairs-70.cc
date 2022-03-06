// 优化：
// 1. 递推公式可以从 1 开始
// 2. for 循环简化代码
//
// 官方题解：
// class Solution {
// public:
//   int climbStairs(int n) {
//     int p = 0, q = 0, r = 1;
//     for (int i = 1; i <= n; ++i) {
//       p = q;
//       q = r;
//       r = p + q;
//     }
//     return r;
//   }
// };
class Solution {
public:
  int climbStairs(int n) {
    // dp[n] = dp[n-1] + dp[n-2] n > 3
    if (n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    } else if (n == 3) {
      return 3;
    }
    int res;
    int a = 3; // dp[n-1]
    int b = 2; // dp[n-2]
    n -= 3;
    while (n--) {
      res = a + b;
      b = a;
      a = res;
    }
    return res;
  }
};

