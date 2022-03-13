class Solution {
public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
      if (i + k <= s.size()) {
        reverse(s, i, i + k);
      } else {
        reverse(s, i, s.size());
      }
    }
    return s;
  }

private:
  void reverse(string &s, int start, int end) {
    while (start < end) {
      swap(s[start++], s[--end]);
    }
  }
};
