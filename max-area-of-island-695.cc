// DFS 和 BFS 都可以解决这道题。
//
// 注意：
//     1. 使用方向数组简化循环
//     2. 坐标的边界情况
//     3. 仅当当前位置的值为 1 时才添加相邻位置到队列
//     4. BFS 过程中需要判断节点是否可处理
//     5. DFS 版本中，参数是 i、j，小心和循环控制变量重名。

// BFS
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> direction{
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0},
    };
    int max_area = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        int area = 0;
        q.push({i, j});
        while (!q.empty()) {
          const auto [curr_i, curr_j] = q.front();
          q.pop();
          if (!isValid(grid, curr_i, curr_j)) {
            continue;
          }
          ++area;
          grid[curr_i][curr_j] = 0;
          for (int i = 0; i < 4; ++i) {
            auto next_i = curr_i + direction[i].first;
            auto next_j = curr_j + direction[i].second;
            q.push({next_i, next_j});
          }
        }
        max_area = max(max_area, area);
      }
    }
    return max_area;
  }

private:
  bool isValid(vector<vector<int>> &grid, int i, int j) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
        grid[i][j] == 1) {
      return true;
    }
    return false;
  }
};

// DFS
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int max_area = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        max_area = max(max_area, dfs(grid, i, j));
      }
    }
    return max_area;
  }

private:
  bool isValid(vector<vector<int>> &grid, int i, int j) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
        grid[i][j] == 1) {
      return true;
    }
    return false;
  }
  int dfs(vector<vector<int>> &grid, int i, int j) {
    if (!isValid(grid, i, j)) {
      return 0;
    }
    grid[i][j] = 0;
    int area = 1;
    vector<pair<int, int>> direction{
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0},
    };
    for (int idx = 0; idx < 4; ++idx) {
      auto next_i = i + direction[idx].first;
      auto next_j = j + direction[idx].second;
      area += dfs(grid, next_i, next_j);
    }
    return area;
  }
};
