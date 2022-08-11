// 基于 BFS 的拓扑排序
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>{});
    vector<int> indegree(numCourses);
    for (const auto &prerequisite : prerequisites) {
      graph[prerequisite[1]].push_back(prerequisite[0]);
      indegree[prerequisite[0]]++;
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < indegree.size(); ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        int course = q.front();
        q.pop();
        ans.push_back(course);
        for (const int prerequisite : graph[course]) {
          indegree[prerequisite]--;
          if (indegree[prerequisite] == 0) {
            q.push(prerequisite);
          }
        }
      }
    }
    if (ans.size() == indegree.size()) {
      return ans;
    }
    return vector<int>{};
  }
};
