// 滑动窗口
//
// 算法：不断向右拓展窗口，出现重复字符串时，缩小窗口左边界，直到重新满足“不存在重复字符”。
//
// 实现：
// - 用 map 记录窗口中每个字符出现的次数。
// - 记录长度需要考虑窗口符合和不符合的情况。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;
        int maxLen = 0;
        for (int left = 0, right = 0; right < s.size(); right++) {
            count[s[right]]++;
            maxLen = max(maxLen, count[s[right]] > 1 ? right-left : right-left+1);
            while (count[s[right]] > 1) {
                maxLen = max(maxLen, right-left);
                count[s[left]]--;
                left++;
            }
        }
        return maxLen;
    }
};
