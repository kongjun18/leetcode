// Dijkstra 算法
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // infinity 不能是 INT_MAX，否则后续的计算会溢出。
    const int infinity = INT_MAX / 2;
    vector<vector<int>> matrix(n, vector<int>(n, infinity));
    vector<int> dist(n, infinity);
    dist[k - 1] = 0;
    vector<bool> visited(n, false);
    // 不能够设置为 visted！起始节点要作为第一个“未访问的距离最小的节点”。
    // visited[k - 1] = true;
    for (const auto &edge : times) {
      matrix[edge[0] - 1][edge[1] - 1] = edge[2];
    }
    // 循环 n - 1 次，计算起始节点到其他节点的最小距离。
    for (int i = 0; i < n; ++i) {
      int min = -1;
      // 找到未访问的距离最小的节点
      for (int j = 0; j < n; ++j) {
        if (!visited[j] && (min == -1 || dist[j] < dist[min])) {
          min = j;
        }
      }
      visited[min] = true;
      // 从此节点更新相邻节点
      for (int j = 0; j < n; ++j) {
        dist[j] = std::min(dist[j], dist[min] + matrix[min][j]);
      }
    }
    const auto max_time = *max_element(dist.cbegin(), dist.cend());
    return max_time == infinity ? -1 : max_time;
  }
};
