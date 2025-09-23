// Dynamic Programming
//
// Let dp[i] denotes the strictly increasing subsequence whose boundary is at i.
// We will notice that dp[i] cannot be transitioned from dp[i-1], as strictly
// increasing subsequence does not require contiguous. dp[i] may be transitioned
// from dp[j] if nums[i] > nums[j] for all j < i. nums[j] is right boundary of
// the subsequence, which is gauranteed by the definition of dp[i].
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    int max_len = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      max_len = max(max_len, dp[i]);
    }
    return result;
  }
};
