// Dynamic Programming
//
// dp[i] represents the maximum product sub-array which ends at index i. the result
// is max_element(dp). How to transfer from i to i+1? Even if the dp[i-1] is the
// maximum product, we cannot get dp[i] simply. For instance, if nums[i] is negative,
// the dp[i] = nums[i] * negative_product_of_subarray[i-1]. That is to say, we need
// to record negative/positive product of sub-arrary that ends at index i and thereby
// calculate maximum product sub-array based on the positivity of nums[i].
//
// To avoid positivity check, I record minimum/maximum product in dp[i][0] and dp[i][1].
// Maximum positive product and minimum negative product is maximum/minimum product naturally.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0] = {nums[0], nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            // min/max avoids positivity check
            dp[i][0] = min(nums[i], min(dp[i-1][0] * nums[i], dp[i-1][1] * nums[i]));
            dp[i][1] = max(nums[i], max(dp[i-1][0] * nums[i], dp[i-1][1] * nums[i]));
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};
