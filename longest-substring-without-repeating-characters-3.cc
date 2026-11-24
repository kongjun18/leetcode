// 滑动窗口
//
// 算法：不断向右拓展窗口，出现重复字符串时，缩小窗口左边界，直到重新满足“不存在重复字符”。
//
// 实现：用 map 记录每个字符出现的次数。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> counter;
        int left = 0;
        int right = 0;
        int maxWindow = 0;
        for ( ; right < s.size(); right++) {
            counter[s[right]]++;
            maxWindow = max(right-left, maxWindow);
            while (counter[s[right]] > 1) {
                counter[s[left]]--;
                left++;
            }
        }
        return maxWindow;
    }
};

// 这个思路有分叉，没有先不断拓展，再判断超出边界的情况容易理解。
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
