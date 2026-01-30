class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < strs.size(); i++) {
            auto s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(i);
        }
        vector<vector<string>> ans;
        for (const auto &[str, idx_list] : m) {
            ans.push_back({});

            for (const auto idx : idx_list) {
                ans.back().push_back(strs[idx]);
            }
        }
        return ans;
    }
};
