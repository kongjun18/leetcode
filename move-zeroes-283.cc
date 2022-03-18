// 典型的双指针
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int slow = 0;
    int fast = 0;
    ;
    for (; fast < nums.size(); ++fast) {
      if (nums[fast] != 0) {
        swap(nums[slow++], nums[fast]);
      }
    }
  }
};
