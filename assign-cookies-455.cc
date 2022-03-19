// 贪心法：努力满足胃口最小的孩子，胃口小的满足后再考虑胃口大的。
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    // 循环使用了类似双指针（快慢指针）的技巧
    int index = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (index < g.size() && g[index] <= s[i]) {
        index++;
      }
    }
    return index;
  }
};
