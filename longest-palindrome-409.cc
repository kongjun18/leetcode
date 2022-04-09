// 回文串要求左右对称，所以除了中心轴上的字符数是单数（1），其他所有字符数都是
// 偶数。
//
// 对任意一种字符，都取最多的偶数个，如果整个字符串还有剩下的，再取一个，就可以
// 构造出最长回文串。
class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> count;
    int length = 0;
    int has_odd = 0;
    for (auto c : s) {
      ++count[c];
    }
    for (const auto [c, n] : count) {
      int is_odd = n % 2;
      length += n - is_odd;
      has_odd = is_odd ? 1 : has_odd;
    }

    return length + has_odd;
  }
};
