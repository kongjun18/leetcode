// Sliding window + Hashing
//
// The same as ./permutation-in-string-567
//
// Use a hash map to record how many times (budget) we can encounter an alphabet in a window,
// decrease it when encounter an alphabet, negative budget means mismatch, indicating
// window shrink.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> m;
        for (const auto ch : p) {
            m[ch]++;
        }

        for (int left = 0, right = 0; right < s.size(); right++) {
            m[s[right]]--;
            while (m[s[right]] < 0) {
                m[s[left]]++;
                left++;
            }
            if (right-left+1==p.size()) {
                res.push_back(left);
            }
        }
        return res;
    }
};
