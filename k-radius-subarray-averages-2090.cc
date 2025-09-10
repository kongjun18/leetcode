// 没什么好说的，固定窗口往后走就行
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(), -1);
        int left = 0, right = 2*k;
        int center = k;
        if (nums.size() < (2*k+1) || k < 0) {
            return res;
        }
        int64_t  sum = accumulate(nums.cbegin(), nums.cbegin() + right+1, 0LL);
        while (right < nums.size()) {
            res[center] = sum / (2*k+1);
            center++;
            right++;
            if (right < nums.size()) {
                sum -= nums[left++];
                sum += nums[right];
            }
        }
        return res;
    }
};
