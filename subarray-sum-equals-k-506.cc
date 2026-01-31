// Brutal force solution
//
// Iterate through all subarray lengths and then scan through the array.
//
// Prefix sum + hashtable solution
//
// We can get the sum of any subarray through prefix sum, where subarray sum equals
// K means prefix[j] - prefix[i] = K. As a result, the issues transform into find
// out how many i exists for each j, where prefix[j] - prefix[i] = K.
//
// We can leverage hashtable to record the number of prefix[i] whose value is
// (prefix[j] - K) where j is the current index.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        // [N], k = N
        cnt[0] = 1;
        vector<int> prev(nums.size());
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prev[i] = sum;
            // we needs the number of prefix[i] whose value is prefix[j] - K,
            // where i MUST be smaller than j. Therefore, we should increment
            // ans in this for loop instead of outside.
            ans += cnt[prev[i] - k];
            // Cornor case: nums = [1], k = 0
            cnt[sum]++;


        }
        return ans;
    }
};
