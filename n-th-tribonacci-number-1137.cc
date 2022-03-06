// 类似：fibonacci-number-509
class Solution {
public:
  int tribonacci(int n) {
    if (n == 0) {
      return 0;
    } else if (n <= 2) {
      return 1;
    }

    int res = 0;
    int a = 1;
    int b = 1;
    int c = 0;
    n -= 2;
    while (n--) {
      res = a + b + c;
      c = b;
      b = a;
      a = res;
    }
    return res;
  }
};
