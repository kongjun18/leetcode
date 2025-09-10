// 解题的关键在于找到循环中不变的模式，也就是每次进行一次螺旋。
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int start_x = 0;
    int start_y = 0;
    int offset = 1;
    int loop = n / 2;
    int count = 1;
    vector<vector<int>> res(n, vector<int>(n));
    while (loop--) {
      int x = start_x;
      int y = start_y;
      for (; y < start_y + n - offset; ++y) {
        res[x][y] = count++;
      }
      for (; x < start_x + n - offset; ++x) {
        res[x][y] = count++;
      }
      for (; y > start_y; --y) {
        res[x][y] = count++;
      }
      for (; x > start_x; --x) {
        res[x][y] = count++;
      }
      ++start_x;
      ++start_y;
      offset += 2;
    }
    // 奇数时，中间会有一个未处理的格子，需要手动处理。
    if (n % 2) {
      res[n / 2][n / 2] = count;
    }
    return res;
  }
};

// 外圈循环完，在内圈重复循环。所有，先硬编码写出最外围的一圈，然后再修改 loop
// 条件，往内圈走。
//
// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> matrix(n, vector<int>(n));
//         int c = 1;
//         int k = n / 2 + (n %2 != 0);
//         for (int j = 0; j < k; j++){
//             for (int i = j; i < n -j; i++) {
//              matrix[j][i] = c++;
//             }
//             for (int i = 1+j; i < n-j; i++) {
//                 matrix[i][n-1-j] = c++;
//             }
//             for (int i=n-1 -1 -j; i >= (0+j); i--) {
//                 matrix[n-1 -j][i] = c++;
//
//             }
//             for (int i = n-1 -1 -j; i > (0+j); i--) {
//                 matrix[i][0+j] = c++;
//             }
//         }
//         return matrix;
//
//     }
// };
