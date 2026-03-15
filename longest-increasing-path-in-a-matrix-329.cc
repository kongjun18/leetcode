// Topological Sort + DFS
//
// 1. Build graph based on increasing paths
// 2. Do Topological sort using DFS to calculate max depth from zero-degree nodes
//
//
// Notes:
// - Since Topologicall sort graph is acyclic, DFS doesn't need to handle visited.
class Solution {
private:
    pair<int, int> node2pos(const vector<vector<int>> &matrix, int node_id) {
        int N = matrix.size();
        int M = matrix[0].size();
        int x = node_id / M;
        int y = node_id % M;
        return {x, y};
    }

    int pos2node(const vector<vector<int>> &matrix, const pair<int, int>& node_pos) {
        int N = matrix.size();
        int M = matrix[0].size();
        auto [x, y] = node_pos;
        return x * M + y;
    }

    int maxDepth(vector<vector<int>> &graph, unordered_map<int, int> &memo, int node) {
        if (memo.count(node)) {
            return memo[node];
        }
        int max_depth = 1;
        for (const auto neighbor : graph[node]) {
            max_depth = max(max_depth, maxDepth(graph, memo, neighbor) + 1);
        }
        memo[node] = max_depth;
        return max_depth;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<vector<int>> graph(N*M);
        int dirs[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        vector<int> in_degree(N*M, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0 ; j < M; j++) {
                for (const auto d : dirs) {
                    int new_i = i + d[0];
                    int new_j = j + d[1];
                    if (new_i < 0 || new_i >= N || new_j < 0 || new_j >= M) {
                        continue;
                    }
                    if (matrix[i][j] < matrix[new_i][new_j]) {
                        int dst = pos2node(matrix, {new_i, new_j});
                        int src = pos2node(matrix, {i, j});
                        graph[src].push_back(dst);
                        in_degree[dst]++;
                    }
                }
            }
        }

        int res = 0;
        unordered_map<int, int> memo;
        for (int i = 0; i < in_degree.size(); i++) {
            if (in_degree[i] == 0) {

               res = max(res, maxDepth(graph, memo, i));
            }
        }
        return res;
    }
};
