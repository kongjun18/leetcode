// ## 2022 approach
// Use a stack to match pairs of brackets.
// Iterate through the string:
// - For an opening bracket, push it onto the stack.
// - For a closing bracket, check the top of the stack.
//   If the stack is empty or the brackets do not match, return false.
// - After processing the string, the stack must be empty.
//   Otherwise, there are unmatched opening brackets, so return false.
class solution {
public:
  bool isvalid(string s) {
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

// ## 2026 approach
// For each character, check whether it matches the top of the stack.
// If it does, pop the top; otherwise, push the character.
// If all brackets are matched, the stack will be empty at the end.
//
// Edge case: }{
// Bracket matching is directional: {} is valid, but }{ is not.
class solution {
private:
    bool matched(char lhs, char rhs) {
        // lhs must be an opening bracket: '{', '(', or '['.
        return m_[lhs] == rhs;
    }
    unordered_map<char, char> m_;
public:
    solution() {
        m_ = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'},

            // Incorrect mapping: treats matching as bidirectional.
            // {'{', '}'},
            // {'}', '{'},
            // {'[', ']'},
            // {']', '['},
            // {'(', ')'},
            // {')', '('},
        };
    }
    bool isvalid(string s) {
        stack<char> sk;

        for (int i = 0; i < s.size(); i++) {
            if (sk.empty() || !matched(sk.top(), s[i])) {
                sk.push(s[i]);
            } else {
                sk.pop();
            }
        }
        return sk.empty();
    }
};
