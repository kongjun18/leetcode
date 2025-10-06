// prime minimum spanning tree
//
// 把所有的点视作图中的节点，所有节点都相连，节点和节点自身不相连，
// 边的权重即 manhattan distance。
class Solution {
    int manhattan_distance(const vector<int> &x, const vector<int> &y) {
        int diff_x = x[0] - y[0];
        int diff_y = x[1] - y[1];
        if (diff_x < 0) {
            diff_x *= -1;
        }
        if (diff_y < 0) {
            diff_y *= -1;
        }
        return diff_x + diff_y;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        set<int> visited;
        int total_cost = 0;
        vector<int> dist(points.size(), INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});

        while (!q.empty()) {
            const auto [distance, node] = q.top();
            q.pop();
            if (visited.count(node) > 0) {
                continue;
            }
            visited.insert(node);
            total_cost += distance;
            for (int i = 0; i < points.size(); i++) {
                if (i == node) {
                    continue;
                }
                int cost = manhattan_distance(points[node], points[i]);
                if (cost < dist[i]) {
                    dist[i] = cost;
                    q.push({cost, i});
                }
            }
        }
        return total_cost;

    }
};
