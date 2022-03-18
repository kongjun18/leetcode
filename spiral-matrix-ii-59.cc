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
