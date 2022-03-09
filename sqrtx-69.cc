// 注意算术溢出。C/C++ 的算术溢出非常恶心，(intmax_t)换个位置就错了，比如
// return (intmax_t)(x * x);
class Solution {
public:
  int mySqrt(int x) {
    int left = 0;
    int right = x;
    int res = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      intmax_t product = pow(mid);
      if (product <= x) {
        res = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return res;
  }

private:
  intmax_t pow(int x) { return (intmax_t)x * x; }
};
