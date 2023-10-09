// 滑动窗口
//
// 算法：窗口是最多经过 K 次字符替换（设置成窗口内出现次数最多的字符）得到重复字符子串。
// 不断向右扩展窗口，但需要进行的字符替换次数大于 K 时，缩小左边窗口。
// 
// NOTE：可能存在扩展窗口右边界但不影响字符替换次数的情况，如 s="AABAA" k=1，窗口
// 右边界拓展到 B 时，字符替换次数为 1，但继续向右拓展窗口不影响字符替换次数。
// 这种情况下要继续向右拓展窗口，因此收缩窗口左边界的条件是字符替换次数大于 k。
class Solution {
public:
  int replaceCharacters(const map<int, int> &m) {
    int sum = 0;
    int maxTimes = 0;
    auto iter = m.cbegin();
    for (int i = 0; i < m.size(); i++) {
      sum += iter->second;
      maxTimes = max(maxTimes, iter->second);
      iter++;
    }
    return sum - maxTimes;
  }

  int characterReplacement(string s, int k) {
    map<int, int> m;
    int maxLen = 0;
    for (int start = 0, end = 0; end < s.size(); ++end) {
      m[s[end]]++;
      while (replaceCharacters(m) > k) {
        maxLen = max(maxLen, end - start);
        m[s[start]]--;
        start++;
      }
      maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
  }
};
