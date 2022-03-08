// See ./hourse-rober-198
class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    return max(robImpl(nums, 0, nums.size() - 1),
               robImpl(nums, 1, nums.size()));
  }

private:
  int robImpl(vector<int> &nums, int start, int end) {
    int houses = end - start;
    if (houses <= 0) {
      return 0;
    } else if (houses == 1) {
      return nums[start];
    } else if (houses == 2) {
      return max(nums[start], nums[start + 1]);
    }
    int r = 0;
    int p = max(nums[start], nums[start + 1]);
    int q = nums[start];
    for (int i = start + 2; i < end; ++i) {
      r = max(p, q + nums[i]);
      q = p;
      p = r;
    }
    return r;
  }
};
