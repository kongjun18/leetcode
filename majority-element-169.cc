// 摩尔投票法
//
// 因为题目说明了存在出现次数超过数组长度二分之一的数，所以不需要第二阶段（计数）。
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int cand = nums[0];
    int vote = 0;
    for (const auto num : nums) {
      if (vote == 0) {
        cand = num;
        ++vote;
      } else if (cand == num) {
        ++vote;
      } else {
        --vote;
      }
    }
    return cand;
  }
};
