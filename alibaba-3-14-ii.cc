// 输入：
// - 第一行输入矩阵维度
// - 其余行是矩阵行的元素
//
// 矩阵元素 0 代表手电筒，1 代表人。手电筒可以向上下左右照射，只要在一个
// 方向照射到人，可照射到人的方向数就加一，求所有手电筒可以照射到人的总方向数。
//
// NOTE：似乎是对的，但是没有完整测试用例。
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> matrix(m, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == 0) {
        // 上下
        for (int k = 0; k < m; ++k) {
          if (matrix[k][j] == 1) {
            ++cnt;
            if (k < i) {
              k = i;
            } else {
              break;
            }
          }
        }
        // 左右
        for (int k = 0; k < n; ++k) {
          if (matrix[i][k] == 1) {
            ++cnt;
            if (k < j) {
              k = j;
            } else {
              break;
            }
          }
        }
      }
    }
  }

  cout << cnt << endl;
  return 0;
}
