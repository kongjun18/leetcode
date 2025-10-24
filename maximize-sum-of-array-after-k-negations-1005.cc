// 贪心
//
// 每次选择最小的元素
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++) {
            auto min_elem = min_element(nums.begin(), nums.end());
            *min_elem = -1 * (*min_elem);
        }
        return accumulate(nums.cbegin(), nums.cend(), 0);
    }
};
