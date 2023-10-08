// 注意数组的递增次序和平方的递增次序。
//
// 元素值离 0 越远，平方越大，因此直接平方后，元素平方从数组两边向中间单
// 调递减。
//
// 计算平方时，从两端向中间遍历，取平方最大的元素，结果数组倒序存放结果
// （从后往前写结果，即从后往前看单调递减，反过来看就是单调递增）。
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> square(nums.size());
    int k = nums.size() - 1;
    for (int i = 0, j = nums.size() - 1; i <= j;) {
      int left = nums[i] * nums[i];
      int right = nums[j] * nums[j];
      if (left <= right) {
        square[k--] = right;
        j--;
      } else {
        square[k--] = left;
        i++;
      }
    }
    return square;
  }
};
