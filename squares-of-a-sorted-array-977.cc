// 注意数组的递增次序和平方的递增次序。
//
// 元素值离 0 越远，平方越大，因此直接平方后，元素平方从数组两边向中间单
// 调递减。
//
// 计算平方时，从两端向中间遍历，取平方最大（绝对值最大）的元素平方，结
// 果数组倒序存放结果（从后往前写结果，即从后往前看单调递减，反过来看就
// 是单调递增）。
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    int i = right;
    vector<int> res(nums.size());
    while (left <= right) {
      if (abs(nums[left]) > abs(nums[right])) {
        res[i--] = pow(nums[left++], 2);
      } else {
        res[i--] = pow(nums[right--], 2);
      }
    }
    return res;
  }
};
