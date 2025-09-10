// 排序加双指针
//
// 暴力解复杂度为 O(n^3)，排序加双指针将内层的两重循环复杂度降为 O(n^2)。
// 双指针要求某种单调性，例如这里一边递增，一边递减。
//
// 注意，题目要求去重，每重循环都要去重和上一个元素相同的解。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size()-1; i++) {
            // 去重
            if (i-1 >= 0) {
                if (nums[i-1]== nums[i]) {
                    continue;
                }
            }

            int left = i+1;
            int right = nums.size()-1;
            while (left < right) {

                int sum = nums[left] + nums[right];
                if (sum < -nums[i]) {
                   left++;
                } else if (sum > -nums[i]) {
                    right--;
                } else { // 去重
                     if (left-1 <= i || nums[left]!=nums[left-1]) {
                        res.push_back({nums[i], nums[left], nums[right]});
                    }
                    left++;
                    continue;


                }

            }
        }
        return res;
    }
};
