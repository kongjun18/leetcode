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


// UnionFind
//
// 用并查集记录每个联通通量的大小，求最大值
//
class Solution {
private:
    struct UnionFind {
        unordered_map<int, int> parent;
        unordered_map<int, int> size;
        int find(int node) {
            if (parent[node] == node) {
                return node;
            }
            // path compression
            parent[node] = find(parent[node]);
            return parent[node];
        }

        void unite(int x, int y) {
            int root_x = find(x);
            int root_y = find(y);
            if (root_x == root_y) {
                return;
            }
            // put the smaller set into the larger set to balance tree height.
            int small_set = root_x < root_y ? root_x : root_y;
            int large_set = root_x < root_y ? root_y : root_x;
            parent[small_set] = large_set;
            size[large_set] += size[small_set];
            size.erase(small_set);
        }

        UnionFind(vector<vector<int>> &grid) {
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 1) {
                        int node = i*grid[0].size()+j;
                        parent[node] = node;
                        size[node] = 1;

                        if (i-1>=0 && grid[i-1][j] == 1) {
                            unite(node, (i-1)*grid[0].size()+j);
                        }
                        if (j-1>=0 && grid[i][j-1] == 1) {
                            unite(node, i*grid[0].size()+j-1);
                        }
                    }
                }
            }
        }
    };
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        UnionFind uf(grid);
        int max_size = 0;
        for (const auto [root, size] : uf.size) {
            max_size = max(max_size, size);
        }
        return max_size;
    }
};
