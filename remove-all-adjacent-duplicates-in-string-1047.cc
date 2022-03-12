// 如果使用 stack 的话，最后要从栈底到栈顶输出。但 STL stack 没有提供这
// 样的接口，最后字符串需要 reverse。使用 deque 代替 stack，方便输出。
class Solution {
public:
  string removeDuplicates(string s) {
    deque<char> match;
    for (auto c : s) {
      if (!match.empty() && match.back() == c) {
        match.pop_back();
      } else {
        match.push_back(c);
      }
    }
    auto res = string{};
    while (!match.empty()) {
      res.push_back(match.front());
      match.pop_front();
    }
    return res;
  }
};
