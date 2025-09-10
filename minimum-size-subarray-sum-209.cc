// 滑动窗口
//
// 算法：
//     右边界前移意味 sum 变大，左边界前移意味 sum 变小。
//     一直拓展窗口右边界先找到大于等于 target 的连续子数组，再缩小左边界查找最小连续数组
// 注意：
//     1. length 计算的时机
//     2. 返回时·要判断length
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int start = 0;
    int end = 0;
    int length = INT_MAX;
    int sum = 0;
    for (end = 0; end < nums.size(); ++end) {
      sum += nums[end];
      while (sum >= target) {
        length = min(length, end - start + 1);
        sum -= nums[start++];
      }
    }
    return length == INT_MAX ? 0 : length;
  }
};
