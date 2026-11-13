class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;

    void dfs(vector<int>& candidates, int target, int start) {
        int sum = accumulate(temp.cbegin(), temp.cend(), 0);
        if (sum == target) {
            result.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); ) {
            if (sum > target) {
                break;
            }
            temp.push_back(candidates[i]);
            dfs(candidates, target, i+1);
            temp.pop_back();
            // Deduplication
            // When skipping duplicate choices at the same level,
            // keep the first occurrence, since choosing the last
            // would make earlier copies unavailable to deeper recursive calls.
            do {
                i++;
            } while (i < candidates.size() && candidates[i-1] == candidates[i]);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates,target, 0);
        return result;
    }
};
