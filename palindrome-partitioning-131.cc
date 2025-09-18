// 回溯算法
//
// Optimization: 用 dp 实现 O(1) 时间判断子串是否回文

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {
    backtracking(s, 0);
    return result;
  }

private:
  vector<vector<string>> result;
  vector<string> alindromes;
  void backtracking(string s, int startIndex) {
    if (startIndex == s.size()) {
      result.push_back(alindromes);
      return;
    }

    for (int i = startIndex; i < s.size(); ++i) {
      if (isAlindrome(s, startIndex, i)) {
        alindromes.push_back(s.substr(startIndex, i - startIndex + 1));
      } else {
        continue;
      }
      backtracking(s, i + 1);
      alindromes.pop_back();
    }
  }
  bool isAlindrome(string s, int start, int end) {
    while (start < end) {
      if (s[start++] != s[end--]) {
        return false;
      }
    }
    return true;
  }
};
