// See max-area-of-island-569
//
// 注意，leetcode 569 的图矩阵元素类型是 int，而这里是
// char。做题要先看题目要求、 数据范围、数据类型等。

// BFS
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> direction{
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0},
    };
    int nr_island = 0;
    bool find_island = false;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        q.push({i, j});
        while (!q.empty()) {
          const auto [curr_i, curr_j] = q.front();
          q.pop();
          if (curr_i < 0 || curr_i >= grid.size() || curr_j < 0 ||
              curr_j >= grid[0].size() || grid[curr_i][curr_j] == '0') {
            continue;
          }
          grid[curr_i][curr_j] = '0';
          find_island = true;
          for (const auto d : direction) {
            q.emplace(curr_i + d.first, curr_j + d.second);
          }
        }
        if (find_island) {
          find_island = false;
          ++nr_island;
        }
      }
    }
    return nr_island;
  }
};

// DFS
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          ++ans;
          dfs(grid, i, j);
        }
      }
    }
    return ans;
  }

private:
  bool isValid(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      return false;
    }
    return true;
  }
  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (!isValid(grid, i, j) || grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';
    static vector<pair<int, int>> direction{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
    for (const auto &dir : direction) {
      dfs(grid, i + dir.first, j + dir.second);
    }
  }
};
