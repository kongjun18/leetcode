#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<list<int>> adjcent_list(numCourses);
    vector<int> indegree(numCourses);
    int count = 0;
    for (int i = 0; i < prerequisites.size(); ++i) {
      adjcent_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
      indegree[prerequisites[i][0]]++;
    }
    auto zero_indegree = find(indegree.begin(), indegree.end(), 0);
    while (zero_indegree != indegree.end()) {
      ++count;
      --(*zero_indegree);
      for (const auto vertex :
           adjcent_list[distance(indegree.begin(), zero_indegree)]) {
        --indegree[vertex];
      }
      zero_indegree = find(indegree.begin(), indegree.end(), 0);
    }
    return count == numCourses;
  }
};

int main (int argc, char *argv[])
{
  int numCourses = 2;
  vector<vector<int>> prerequisites{{1, 0}};
  cout << Solution{}.canFinish(numCourses, prerequisites) << endl;
  return 0;
}
