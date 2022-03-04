// Leetcode 77: Combinations
//
// NOTE:
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
