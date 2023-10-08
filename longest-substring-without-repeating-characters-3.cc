// 滑动窗口
//
// 算法：不断向右拓展窗口，出现重复字符串时，缩小窗口左边界，直到重新满足“不存在重复字符”。
//
// 实现：可以使用 set 记录重复情况，也可以使用 map 记录每个字符出现的次数。
//       map 的实现更加简单。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<int, int> m;
        for (int start = 0, end = 0; end < s.size(); end++) {
            ++m[s[end]];
            while (m[s[end]] > 1) {
                --m[s[start]];
                if (m[s[start]] == 0) {
                    m.erase(s[start]);
                }
                ++start;
            }
            maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};

// 注意：小心区间的变化，尤其是在边界。
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> repeated;
    int start = 0;
    int end = 0;
    int length = 0;
    for (; end < s.size(); ++end) {
      if (repeated.find(s[end]) == repeated.end()) {
        repeated.insert(s[end]);
        length = max(length, end - start + 1);
      } else {
        while (repeated.find(s[end]) != repeated.end()) {
          repeated.erase(s[start++]);
        }
        // 如果不插入，此元素会错误地加入到区间中。考虑以下输入：
        // Input: s = "pwwkew"
        repeated.insert(s[end]);
      }
    }
    return length;
  }
};
