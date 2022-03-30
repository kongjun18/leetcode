class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() < 2) {
      return nums.size();
    }
    vector<int> dp(nums.size(), 1);
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      if (result < dp[i]) {
        result = dp[i];
      }
    }
    return result;
  }
};
