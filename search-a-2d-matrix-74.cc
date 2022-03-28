// 二分查找的变形题
//
// 将二维数组拼接成一维数组进行二分查找，这个解法只适用于列数相同的矩阵。
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
      return false;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int size = n * m;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (matrix[row(mid, m)][col(mid, m)] == target) {
        return true;
      } else if (matrix[row(mid, m)][col(mid, m)] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }

private:
  int col(int i, int m) { return i % m; }
  int row(int i, int m) { return i / m; }
};

// 两次二分查找
// 1. 查找到目标所在的行
// 2. 在目标所在行内二分查找
//
// 这种解法可以处理列数不同的矩阵
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    auto row = upper_bound(
        matrix.cbegin(), matrix.cend(), target,
        [](int target, const vector<int> &arr) { return target < arr[0]; });
    if (row == matrix.cend()) {
      row = matrix.cbegin() + matrix.size() - 1;
    } else {
      row -= (row != matrix.cbegin());
    }
    return binary_search(row->cbegin(), row->cend(), target);
  }
};
