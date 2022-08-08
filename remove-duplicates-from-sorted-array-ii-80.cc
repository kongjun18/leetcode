// remove-duplicates-from-sorted-array-26 的姊妹题。
//
// remove-duplicates-from-sorted-array-26 nums[slow-1] 和 nums[fast] 比较，保留
// 一个重复元素；nums[slow-2] 和 nums[fast] 比较，保留两个重复元素。
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 2) {
      return nums.size();
    }
    int slow = 2;
    int fast = 2;
    for (; fast < nums.size(); fast++) {
      if (nums[slow - 2] != nums[fast]) {
        nums[slow++] = nums[fast];
      }
    }
    return slow;
  }
};
