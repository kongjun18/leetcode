// 不是 Leetcode 题目
// 讲解参考：
// [代码随想录：咱就把0-1背包问题讲个通透！](https://zhuanlan.zhihu.com/p/345364527)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> weight = {1, 3, 4};
vector<int> value = {15, 20, 30};
int bagWeight = 4;

// weight[i] <= j:
//     dp[i][j] = max{dp[i-1][j], dp[i-1][j-weight[i]] + value[i]}, i >= 1
// else:
//     dp[i][j] =dp[i-1][j]
auto TwoDimensionKnapsack() -> void {
  // assert: bags >= 1
  int bags = weight.size();
  auto dp = vector(bags, vector(bagWeight + 1, 0));
  for (int i = weight[0]; i <= bagWeight; ++i) {
    dp[0][i] = value[0];
  }
  for (int i = 1; i < bags; ++i) {
    for (int j = 0; j <= bagWeight; ++j) {
      if (j < weight[i]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        // 为什么不能直接 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]]
        // + value[i])？
        //
        // 因为当且仅当 j >= weight[i] 才可能把物品 i 放入背包。
        //
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
      }
    }
  }
  for (const auto &line : dp) {
    for (const auto &elem : line) {
      cout << elem << "\t";
    }
    cout << endl;
  }
}

// Two demension:
//     dp[i][j] = max{dp[i-1][j], dp[i-1][j-weight[i]] + value[i]}
//     condition: i >= 1 && j >= weight[i]
// Single demension:
//     dp[j] = max{dp[j], dp[j-weight[i]] + value[i]}
//     condition: i >= 1 && j >= weight[i]
//
//
// 一维版本实际上是：
// 1. 隐式地实现了二维版本的外层循环（物品）
// 2. 利用仅在 i >= 1 && j >= weight[i] 时可能需要修改 dp[j]
//    的事实，避免二维中的 if 判断。
void SingleDimensionKnapsack() {
  int bags = weight.size();
  auto dp = vector(bagWeight + 1, 0);
  for (int i = 0; i < bags; ++i) {
    // 为了保证物品i只被放入一次，倒序遍历。
    //
    // 如果正序遍历，当 dp[j] = dp[j - weight[i]] + value[i] 时，dp[j-weight[i]]
    // 可能已经将物品 i 放入到背包中，导致重复选取(01 背包中，物品 i 只有一个)。
    //
    // 从 dp 数组的语义上看，dp[j] 表示前 i 个物品，在背包重量为 j
    // 的情况下，能取得的最大价值。dp[j] = dp[j - weight[i]] + value[i] 表示在前
    // i-1 个物品最大价值的基础上，把物品 i 加入到背包中，相当于二维版本的
    // dp[i][j] = dp[i-1][j-weight[i-1]] + value[i]。如果正序选择，遍历到 dp[j]
    // 时，dp[j - weight[i]] 表示前 i 个物品的最大价值，相当于二维版本的
    // dp[j][j-weight[i-1]]。
    //
    // 当 j < weight[i] 时，dp[j] = dp[j]，值不变，
    // 所以在此一维滚动数组的实现中， 设置 j >= weight[i] 为循环条件。
    for (int j = bagWeight; j >= weight[i]; --j) {
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  for (const auto &elem : dp) {
    cout << elem << "\t";
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  TwoDimensionKnapsack();
  cout << "\n\n";
  SingleDimensionKnapsack();
  return 0;
}
