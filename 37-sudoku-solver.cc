//
// Leetcode 37: https://leetcode.com/problems/sudoku-solver/
//

// 这是我完成的第一道回溯题目。
//
// 回溯三部曲：
// 1. 递归参数和返回值
// 2. 终止条件
// 3. 每层执行的操作
//
// 我的解法从可选的数字入手，每个格子有 9 种可选数字，所以循环 9 次，每个数字都
// 对应下一个格子的 9 种可能，依次类推。我的解法通过 solveSudokuImpl() 的参数 count
// 实现遍历所有的格子，代码随想录给出的解法使用两重循环遍历所有格子（if 语句避免
// 重复计算）。
//
// 这道题目有两个关键的地方：
// 1. 如何判断取到的数字让数度满足条件（isOk())？
//     要注意递归时是有方向性的，是从第一个格子到最后一个格子。当前选中的格子
//     之前的正确性已经有了保证，只需要坚持当前格子填入数字后数度是否正确即可。
// 2. 如果避免在填满后回溯导致数度恢复原状？
//     看回溯三部曲的第一二步！这里的终止条件是填入最后一个格子（第 81 个）后
//     数度满足条件，从递归树的角度看就是找到了一个满足条件的叶子节点。为了避
//     免填满数度后回溯导致恢复原状,必须在填满后打断“回溯链”，这就要用到三部曲
//     中的第一步了！设置 solveSudokuImpl() 返回值为 bool,如果返回 true 说明已
//     经填满树度，直接退出函数，不恢复填入的数字。
//
// NOTE： 这里说的“回溯链”不是指递归的回溯过程，而是指下一层递归函数返回后，可能
//        需要的清除填入的数字的操作。见 代码 56 行。
//
// Tip：  让数字 N 对其到 n 边界： N * n / n。见 代码 81 行。
#include <cstdio>
#include <vector>
using namespace std;

void print(vector<vector<char>> &board) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      printf("%c\t", board[i][j]);
    }
    printf("\n");
  }
}
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { solveSudokuImpl(board, 0); }

private:
  bool solveSudokuImpl(vector<vector<char>> &board, int count) {
    if (count == 81) { // count: 0~81
      return true;
    }
    int col = count % 9;
    int row = count / 9;
    for (char i = '1'; i <= '9'; ++i) {
      if (board[row][col] != '.') {
        return solveSudokuImpl(board, count + 1);
      }
      if (isOk(board, count, i)) {
        board[row][col] = i;
        if (solveSudokuImpl(board, count + 1)) {
          return true;
        }
        board[row][col] = '.';
      }
    }
    return false;
  }

  bool isOk(vector<vector<char>> &board, int count, int val) {
    int col = count % 9;
    int row = count / 9;
    // check line
    for (int i = 0; i < 9; ++i) {
      if (board[row][i] == val) {
        return false;
      }
    }
    // check column
    for (int i = 0; i < 9; ++i) {
      if (board[i][col] == val) {
        return false;
      }
    }
    // check 3x3 sub-box
    for (int i = row / 3 * 3, row_cnt = 0; row_cnt < 3; ++row_cnt) {
      for (int j = col / 3 * 3, col_cnt = 0; col_cnt < 3; ++col_cnt) {
        if (board[i + row_cnt][j + col_cnt] == val) {
          return false; // 子区域没有填满，认为一切正常。
        }
      }
    }

    return true;
  }
};

// class Solution {
// private:
//   bool backtracking(vector<vector<char>> &board) {
//     for (int i = 0; i < board.size(); i++) {      // 遍历行
//       for (int j = 0; j < board[0].size(); j++) { // 遍历列
//         if (board[i][j] != '.')
//           continue;
//         for (char k = '1'; k <= '9'; k++) { // (i, j) 这个位置放k是否合适
//           if (isValid(i, j, k, board)) {
//             board[i][j] = k; // 放置k
//             if (backtracking(board))
//               return true;     // 如果找到合适一组立刻返回
//             board[i][j] = '.'; // 回溯，撤销k
//           }
//         }
//         return false; // 9个数都试完了，都不行，那么就返回false
//       }
//     }
//     return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
//   }
//   bool isValid(int row, int col, char val, vector<vector<char>> &board) {
//     for (int i = 0; i < 9; i++) { // 判断行里是否重复
//       if (board[row][i] == val) {
//         return false;
//       }
//     }
//     for (int j = 0; j < 9; j++) { // 判断列里是否重复
//       if (board[j][col] == val) {
//         return false;
//       }
//     }
//     int startRow = (row / 3) * 3;
//     int startCol = (col / 3) * 3;
//     for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
//       for (int j = startCol; j < startCol + 3; j++) {
//         if (board[i][j] == val) {
//           return false;
//         }
//       }
//     }
//     return true;
//   }
//
// public:
//   void solveSudoku(vector<vector<char>> &board) { backtracking(board); }
// };

int main() {
  vector<vector<char>> test_case1{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  vector<vector<char>> test_case2{
      {'.', '.', '9', '7', '4', '8', '.', '.', '.'},
      {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
      {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
      {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
      {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
      {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
      {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};

  Solution{}.solveSudoku(test_case1);
  print(test_case1);
  Solution{}.solveSudoku(test_case2);
  print(test_case2);
}
