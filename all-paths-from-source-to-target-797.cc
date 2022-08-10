// DFS 模版题
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
