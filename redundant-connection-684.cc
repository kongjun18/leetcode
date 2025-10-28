// Solution 1: Topological Sort
//
// 1. Remove all nodes that are not in the cycle using topological sort.
// 2. Remove the edge that occurs last in the input.
//
// Notes:
// - The graph is undirected graph and thus each node's indegree is at least 1.
//   Hence, topological sorting should select nodes whose indegree == 1.
// - The graph is sparse so adjacent linked list is more suitable.
//
//
// Solution 2: Union Find
//
// Iterate through all edges, if vertexs are not in the union find, connect it.
// If encounter a edge whose vertex are already in the union find, it causes
// cycle! Hence, this edge is what we want.
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> zero_degree;
        int N = 0;
        for (const auto &edge : edges) {
            N = max(N, max(edge[0], edge[1])+1);
        }
        vector<int> degree(N);

        vector<vector<int>> matrix(N, vector<int>(N));
        for (int i = 0; i < edges.size(); i++) {
            matrix[edges[i][0]][edges[i][1]] = 1;
            matrix[edges[i][1]][edges[i][0]] = 1;
            degree[edges[i][1]]++;
            degree[edges[i][0]]++;
        }
        for (int vertex = 1; vertex < N; vertex++) {
            if (degree[vertex] == 1) {
                zero_degree.push_back(vertex);
            }
        }
        std::cout << zero_degree.size() << std::endl;
         while (!zero_degree.empty()) {
            int vertex = zero_degree.back();
            zero_degree.pop_back();
            for (int i = 1; i < N; i++) {
                if (matrix[vertex][i]) {
                    matrix[vertex][i] = 0;
                    matrix[i][vertex] = 0;

                    degree[i]--;
                    if (degree[i] == 1) {
                        zero_degree.push_back(i);
                    }
                }
            }
        }

        for (int i = edges.size()-1; i >= 0; i--) {
            if (matrix[edges[i][0]][edges[i][1]]) {
                return edges[i];
            }
        }
        return {-1, -1};
    }
};

// UnionFind
class Solution {
    // Only needs unite, find and connected.
    vector<int> parents;
    void unite(int x, int y) {
        parents[find(x)] = find(y);
    }
    int find(int x) {
        while (parents[x] != x) {
            x = parents[x];
        }
        return parents[x];
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = -1;
        for (int i = 0; i < edges.size(); i++) {
            const auto edge = edges[i];
            N = max(N, max(edge[0], edge[1])+1);
        }

        parents.resize(N);
        for (int i = 0; i < N; i++) {
            parents[i] = i;
        }

        for (int i = 0; i < edges.size(); i++) {
            const auto edge = edges[i];
            if (!connected(edge[0], edge[1])) {
                unite(edge[0], edge[1]);
            } else {
                return {edge[0], edge[1]};
            }

        }
        return {-1, -1};
    }
};
