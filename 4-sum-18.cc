// 取下标 i 的元素为的一个元素，在区间 [i+1, nums.size()) 中进行三数求和。
// 更高阶的 N 数求和同理。
//
// 注意：
// - 第二个元素和第一个元素相邻的情况要特殊处理，不能视作去重的情况。
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i + 3 < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) { // 对第一个元素去重
        continue;
      }
      target -= nums[i];
      for (int j = i + 1; j + 2 < nums.size(); ++j) {
        // 对于 j == i + 1 时，nums[j] 是三数之和的第一个元素，不能去重。
        if (j > 0 && j != i + 1 && nums[j] == nums[j - 1]) { // 对第二个元素去重
          continue;
        }
        target -= nums[j];
        int left = j + 1;
        int right = nums.size() - 1;
        while (left < right) {
          int sum = nums[left] + nums[right];
          if (sum == target) {
            res.push_back(
                vector<int>{nums[i], nums[j], nums[left], nums[right]});
            while (++left < nums.size() && nums[left] == nums[left - 1]) {
            } // 对第三个元素去重
            while (--right > j && nums[right] == nums[right + 1]) {
            } // 对第四个元素去重
          } else if (sum < target) {
            ++left;
          } else {
            --right;
          }
        }
        target += nums[j];
      }
      target += nums[i];
    }
    return res;
  }
};
