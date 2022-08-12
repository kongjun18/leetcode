// 基于路径压缩的并查集
class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> parent(isConnected.size());
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected.size(); ++j) {
                if (isConnected[i][j]) {
                    combine(parent, i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == i) {
                ++cnt;
            }
        }
        return cnt;
    }
private:
    void combine(vector<int> &parent, int i, int j) {
        parent[find(parent, i)] = parent[find(parent, j)];
    }
    int find(vector<int> &parent, int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
};
