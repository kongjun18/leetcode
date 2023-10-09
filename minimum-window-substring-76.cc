// 滑动窗口
//
// 算法：窗口是包含全部目标字符的字串，窗口不断向右扩张，
// 扩张到包含全部目标字符后，缩小左边边界以查找最短字串。
//
// 关键点：题目的难点是如何判断窗口已包含全部目标字串，这通过记录
// 目标字符在 t 中的次数和在窗口中出现的次数判定。
//
// 备注：滑动窗口的题目尽量避免使用 map 的 size() 和 find()，直接
// 访问 key 是最方便的。比较下面两个代码就能看到这一点。
class Solution {
public:
    bool allTargetCharFound(unordered_map<int, int> &m, unordered_map<int, int> &c) {
        for (const auto [ch, times] : m) {
            if (c[ch] < times) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<int, int> m;
        for (const auto ch : t) {
            m[ch]++;
        }
        unordered_map<int, int> c;
        int left = 0, right = s.size();
        for (int start=0,end=0; end < s.size(); end++) {
            c[s[end]]++;
            while(allTargetCharFound(m, c)) {
                if ((end-start) < (right-left)) {
                    left = start;
                    right = end;
                }
                c[s[start]]--;
                start++;
            }
        }
        return (right == s.size()) ? "" : s.substr(left, right-left+1);
    }
};

class Solution {
public:
  bool foundAllTargetChars(const unordered_map<int, int> &m,
                           const unordered_map<int, int> &counter) {
    if (counter.size() != m.size()) {
      return false;
    }
    for (const auto elem : counter) {
      const auto iter = m.find(elem.first);
      if (iter != m.cend()) {
        if (iter->second > elem.second) {
          return false;
        }
      }
    }
    return true;
  }
  string minWindow(string s, string t) {
    unordered_map<int, int> m;
    for (const auto c : t) {
      m[c]++;
    }
    auto subString = make_pair(0, s.size());
    unordered_map<int, int> counter;
    for (int start = 0, end = 0; end < s.size(); end++) {
      if (m.find(s[end]) != m.cend()) {
        counter[s[end]]++;
      }
      while (foundAllTargetChars(m, counter)) {
        if ((end - start) < (subString.second - subString.first)) {
          subString = make_pair(start, end);
        }
        if (counter.find(s[start]) != counter.cend()) {
          --counter[s[start]];
          if (counter[s[start]] == 0) {
            counter.erase(s[start]);
          }
        }
        ++start;
      }
    }

    if (subString.second == s.size()) {
      return "";
    }
    return s.substr(subString.first, subString.second - subString.first + 1);
  }
};
