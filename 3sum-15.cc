// 排序加双指针
//
// 暴力解复杂度为 O(n^3)，排序加双指针将内层的两重循环复杂度降为 O(n^2)。
// 双指针要求某种单调性，例如这里一边递增，一边递减。
//
// 这里的难点在于去重
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int prev = -1;
        for (int i = 0; i < nums.size(); i++) {
            // 去重
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;
            int target = 0 - nums[i];
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // 先移动指针，后去重。
                    // 避免复杂的边界条件。
                    while (j < k && nums[j-1] == nums[j]) j++;
                    while (j < k && nums[k+1] == nums[j]) k--;
                } else if (sum < target) {
                    j++;
                } else {
                   k--;
                }
            }
        }
        return ans;
    }
};
