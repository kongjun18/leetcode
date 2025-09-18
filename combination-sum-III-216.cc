// 类似：combinations-77
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    backtracking(k, n, 1);
    return result;
  }

private:
  vector<int> path;
  vector<vector<int>> result;
  void backtracking(int k, int n, int val) {
    if (path.size() == k) {
      if (accumulate(path.cbegin(), path.cend(), 0) == n) {
        result.push_back(path);
      }
      return;
    }
    for (int v = val; v <= 9; ++v) {
      path.push_back(v);
      backtracking(k, n, v + 1);
      path.pop_back();
    }
  }
};
