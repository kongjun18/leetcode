class Solution {
private:
    int sum = 0;
    vector<int> result;
    vector<vector<int>> results;
    void backtracking(vector<int>& candidates, int target, int start, int sum) {
        for (int i = start; i < candidates.size(); i++) {
            // 题目要求不能重复，且不要求结果次序
            if (i > start && candidates[i]== candidates[i-1]) {
                continue;
            }
            int new_sum = sum + candidates[i];
            result.push_back(candidates[i]);
            if (new_sum == target) {
                results.push_back(result);
                // 注意，题目没有限制数字个数，即使找到结果还有继续找。
                result.pop_back();
                continue;
            } else {
                // 剪枝：只有可能有结果时才递归。
                int diff = target - new_sum;
                if (diff >= candidates[i] && diff <= (candidates.size()-result.size())*candidates.back()) {
                    backtracking(candidates, target, i+1, new_sum);
                }
            }
            result.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);
    return  results;
    }
};
