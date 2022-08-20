// 顾客付款金额只有以下三种情况：
// - 5 美元：不需要找零。
// - 10 美元：只能找 5 美元。
// - 20 美元：找 15 美元，可以是 1 张 5 美元和 1 张 10 美元，也可以是 3 张 5 美元。
//
// 5 美元和 10 美元的情况只有一种找零可能，问题的关键在于顾客支付 20 美元后，应
// 该找 10+5 美元还是 3*5 美元？
//
// 思考的落脚点在于怎样找零才能尽可能地让尽可能给后续顾客找零。显然，5 美元的组
// 合可以应对更多的顾客付款组合，因为找零总是 5 美元或 15 美元，只需要有足够的
// 5 美元或 5+10 美元的组合就可以满足找零需求。假如优先找零 5 美元，可能存在手
// 上有 10 美元，但是顾客需要 5 美元无法找零的情况。因此找零的规则是“尽可能让手上有
// 足够多的 5 美元”。
class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    unordered_map<int, int> cnt;
    for (const auto bill : bills) {
      cnt[bill]++;
      switch (bill) {
      case 10:
        if (cnt[5] == 0) {
          return false;
        }
        cnt[5]--;
        break;
      case 20:
        if (cnt[10] > 0 && cnt[5] > 0) {
          cnt[10]--;
          cnt[5]--;
        } else if (cnt[5] >= 3) {
          cnt[5] -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
