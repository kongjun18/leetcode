// 栈匹配对称的符号。
// 遍历字符串：
// - 对于左边的符号，压入栈顶
// - 对于右边的符号，查看栈顶符号，如果不匹配则返回  false.
// - 遍历结束后，如果符号匹配，则堆栈为空，否则返回 false。这是为了避免左边符号
//   多于右边符号的情况。
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> m{
        {']', '['},
        {'}', '{'},
        {')', '('},
    };
    for (auto c : s) {
      switch (c) {
      case '(':
      case '[':
      case '{':
        st.push(c);
        break;
      default:
        if (st.empty() || st.top() != m[c]) {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }
};
