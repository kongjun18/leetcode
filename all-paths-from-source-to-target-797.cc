// DFS 模版题 推荐backtracking写法
//
// 类似于遍历树找一条合法路径，从根 DFS，记录路径遇到叶子节（这里是出度为0的节
// 点）就将路径压入到路径数组中。
class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<int> path;
    vector<vector<int>> ans;
    dfs(ans, graph, 0, path);
    return ans;
  }

private:
  void dfs(vector<vector<int>> &ans, vector<vector<int>> &graph, int vertex,
           vector<int> &path) {
    path.push_back(vertex);
    if (vertex == graph.size() - 1) {
      ans.push_back(path);
    }
    for (const auto adjcent : graph[vertex]) {
      dfs(ans, graph, adjcent, path);
    }
    path.pop_back();
  }
};

// Backtracking 写法
class Solution {
private:
    vector<vector<int>> results;
    vector<int> path;
    void dfs(vector<vector<int>> &graph, int vertex) {
        if (vertex == graph.size()-1) {
            results.push_back(path);
            return;
        }

        for (const auto adjacent : graph[vertex]) {
            path.push_back(adjacent);
            dfs(graph, adjacent);
            path.pop_back();

        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return results;
    }
};
