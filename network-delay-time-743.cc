// 基于 BFS 和优先级队列的 Dijkstra 算法
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    const int infinity = 0x3f3f3f;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> dist(n, infinity);
    for (const auto &edge : times) {
      graph[edge[0] - 1].push_back(make_pair(edge[1]-1, edge[2]));
    }
    auto cmp = [&](int a, int b) {
      return dist[a] < dist[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    dist[k-1] = 0;
    q.push(k-1);
    while (!q.empty()) {
      int v = q.top();
      q.pop();
      for (const auto &edge : graph[v]) {
        if (dist[v] + edge.second < dist[edge.first]) {
          dist[edge.first] = dist[v]+edge.second;
          q.push(edge.first);
        }
      }
    }
    auto max_time = *max_element(dist.cbegin(), dist.cend());
    if (max_time == infinity) {
      return -1;
    }
    return max_time;
  }
};

// 基于矩阵与动态规划的 Dijkstra 算法
// 这个算法不好理解和实现
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // infinity 不能是 INT_MAX，否则后续的计算会溢出。
    const int infinity = 0x3f3f3f;
    vector<vector<int>> matrix(n, vector<int>(n, infinity));
    vector<int> dist(n, infinity);
    dist[k - 1] = 0;
    vector<bool> visited(n, false);
    // 不能够设置为 visted！起始节点要作为第一个“未访问的距离最小的节点”。
    // visited[k - 1] = true;
    for (const auto &edge : times) {
      matrix[edge[0] - 1][edge[1] - 1] = edge[2];
    }
    // 循环 n 次，计算起始节点到其他节点的最小距离。
    for (int i = 0; i < n; ++i) {
      int min = -1;
      // 找到未访问的距离最小的节点
      for (int j = 0; j < n; ++j) {
        if (!visited[j] && (min == -1 || dist[j] < dist[min])) {
          min = j;
        }
      }
      visited[min] = true;
      // 从此节点更新相邻节点最短距离
      for (int j = 0; j < n; ++j) {
        dist[j] = std::min(dist[j], dist[min] + matrix[min][j]);
      }
    }
    const auto max_time = *max_element(dist.cbegin(), dist.cend());
    return max_time == infinity ? -1 : max_time;
  }
};

