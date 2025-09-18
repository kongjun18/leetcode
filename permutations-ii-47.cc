// 回溯
//
// 每次从集合选择一个元素，直到集合中所有元素都选择过。
class Solution {
private:
    unordered_set<int> selected;
    vector<int> result;
    vector<vector<int>> results;
    void backtracking(vector<int> &nums) {
        if (result.size()==nums.size()) {
            results.push_back(result);
        }
        unordered_set<int> used;
        for (int i = 0; i < nums.size(); i++) {
            // selected 判断该元素是否选择过，在递归中有效。
            if (selected.count(i)) {
                continue;
            }
            // used 去重，在循环中有效
            if (used.count(nums[i])) {
                continue;
            }
            // WARNING： selected 的插入不能放在 selected.count(i) 之后，
            // 否则可能出现 used.count(nums[i]) == true 的情况，导致 selected
            // 不会进入回溯阶段被回复。
            used.insert(nums[i]);
            selected.insert(i);

            result.push_back(nums[i]);
            backtracking(nums);
            // 回溯和回复
            result.pop_back();
            selected.erase(i);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtracking(nums);
        return results;
    }
};
