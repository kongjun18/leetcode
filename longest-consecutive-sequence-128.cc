// Hash table
//
// The naive algorithm is sort the nums and traverse to find out the result,
// where checking whether the sequence is consecutive by increment the number.
// That is to say, **we can construct a consecutive sequence once we have a starting
// point** and can check the map/set to determine whether the consecutive sequence
// exists.
//
// To avoid duplicate consecutive sequence searching, we only search at the
// starting point. See line 20.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        unordered_set<int> s;
        for (const auto num : nums) {
            s.insert(num);
        }
        for (auto num: s) {
            if (s.find(num-1) != s.end()) {
                continue;
            }
            int cnt = 1;
            while (true) {
                num++;
                if (s.find(num) != s.end()) {
                    cnt++;
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);

        }
        return ans;
    }
};
