// Leetcode 77: Combinations
//
// - 从横向（每层）和纵向两个方向思考
// - 参数用来深入递归
// - 返回值用来控制递归过程的返回（通常是 bool 值，参考 sudoku-solver-37.cc）

// 代码模板：
// void backtracking(参数) {
//   if (终止条件) {
//     存放结果;
//     return;
//   }
//
//   for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
//     处理节点;
//     backtracking(路径，选择列表); // 递归
//     回溯，撤销处理结果
//   }
// }
//
// 另外一种解法是看作遍历一个数字序列的集合，遍历符合条件的序列。
// 可能的序列的数字是 1-9，且每个数字只能出现一次，可以用一个 int 数字，每个 bit
// 表示这个序列的数字的 membership，遍历所有可能序列，找到符合条件的。

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    backtracking(n, k, 1);
    return result;
  }

private:
  void backtracking(int n, int k, int start) {
    if (temp.size() == k) {
      result.push_back(temp);
      return;
    }
    for (int i = start; i <= n; ++i) {
      temp.push_back(i);
      backtracking(n, k, i + 1);
      temp.pop_back();
    }
  }
  vector<vector<int>> result;
  vector<int> temp;
};

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
public:

    vector<vector<int>> combinationSum3(int k, int n) {
      // mask records the membership of each number in the candidate number sequence.
      // We interate over all possible sequences and collect sequences that meets
      // the requirements.
      for (int mask = 1; mask < (1 << 9); mask++) {
          temp.clear();
          for (int i = 0; i < 9; i++) {
              if (mask & (1<<i)) {
                  temp.push_back(i+1); // i+1 instead of i
              }
          }
          if (temp.size() == k && accumulate(temp.cbegin(), temp.cend(), 0) == n) {
              result.push_back(temp);
              temp.clear();
          }
      }
      return result;
    }
};
