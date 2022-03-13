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
