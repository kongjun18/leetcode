// 1. 迭代
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

// 2. 递归
class Solution {
    void reverseStr(string &s, size_t pos, int k) {
        if (pos >= s.size()) {
            return;
        }
        int left = pos, right = min(static_cast<size_t>(pos+k-1), s.size()-1);
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        reverseStr(s, pos + 2*k, k);

    }
public:
    string reverseStr(string s, int k) {
        reverseStr(s, 0, k);
        return s;
    }
};
