// 哈希表
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> num2idx;
    for (int i = 0; i < nums.size(); ++i) {
      num2idx[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
      auto iter = num2idx.find(target - nums[i]);
      if (iter != num2idx.end() && iter->second != i) {
        return {i, iter->second};
      }
    }
    return {};
  }
};
