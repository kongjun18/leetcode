// Backtracking with memo optimization
class Solution {
    unordered_map<int, int> memo;
private:
    bool dfs(string &s, vector<string>& wordDict, int start) {
        if (start == s.size()) {
            return true;
        }
        for (const auto &word : wordDict) {
            if (word.size() + start > s.size()) {
                continue;
            }
            if (word == s.substr(start, word.size())) {
                if (memo.find(start)==memo.end()) {
                    auto result = dfs(s, wordDict, start+word.size());
                    if (result) {
                        memo[start]=true;
                        return true;
                    }
                } else if (memo[start] == 1) {
                    return true;
                } else {
                    continue; // false
                }

            }
        }
        memo[start] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict, 0);
    }
};
