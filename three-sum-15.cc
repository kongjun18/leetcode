// 1. 如何降低复杂度？
//     - 三数之和暴力解法需要三重循环，复杂度为 O(n^3)。双指针可以在一重循环中
//       完成两重循环才能完成的事，将复杂度降为 O(n^2)。
// 2. 如何去重？
//     - 第一个数（三数最左边的数）和其前面相邻的数相同，可能出现重复的结果。
//     - 第二个数和其前面相邻的数相同，可能存在重复的结果。
//     - 第三个数和其后面相邻的叔相同，可能存在重复的结果。
//
//     如果三数之和不等于 0，不需要考虑第二、三个数重复的情况，虽然数字重复，但
//     和不为零，不在结果中。
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {

    vector<vector<int>> res;

    if (nums.empty()) {
      return res;
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i + 2 < nums.size(); ++i) {
      int left = i + 1;
      int right = nums.size() - 1;
      if (i > 0 && nums[i] == nums[i - 1]) { // 去重，第一个数重复。
        continue;
      }
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          res.push_back(vector<int>{nums[i], nums[left], nums[right]});
          // 去重，第二个数重复。
          while (++left < nums.size() && nums[left - 1] == nums[left]) {
          }
          // 去重，第三个数重复。
          while (--right > i && nums[right] == nums[right + 1]) {
          }
        } else if (sum < 0) {
          ++left;
        } else {
          --right;
        }
      }
    }
    return res;
  }
};
