// 回溯
class Solution {
    vector<vector<int>> results;
    vector<int> result;
private:
    voi backtracking(vector<int> &nums,int start) {
        // 收集结果
        if (result.size() > 1) {
            results.push_back(result);
        }

        unorered_set<int> used;
        for (int i = start; i < nums.size(); i++) {
            // 剪枝
            if (!result.empty() && result.back() > nums[i]) {
                continue;
            }
            if (used.count(nums[i])) {
                continue;
            }

            // 本层逻辑
            used.insert(nums[i]);
            result.push_back(nums[i]);
            // 递归
            backtracking(nums, i+1);
            // 回溯
            result.pop_back();
        }

    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return results;
    }
};
