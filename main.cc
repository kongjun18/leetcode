#include <forward_list>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
enum NODE_TYPE {
  DISCOVERED,
  UNDISCOVERED,
  VISITED,
};

vector<forward_list<int>> createTable(vector<int> &A, vector<int> &B, int N) {
  vector<forward_list<int>> res(N, forward_list<int>());
  for (int i = 0; i < A.size(); ++i) {
    int a = A[i];
    int b = B[i];
    res[a].insert_after(res[a].before_begin(), b);
    res[b].insert_after(res[b].before_begin(), a);
  }
  return res;
}


int bfs(vector<forward_list<int>> table, int src, vector<int> &H) {
  queue<int> Q;
  vector<NODE_TYPE> status(table.size(), UNDISCOVERED);
  status[src] = DISCOVERED;
  Q.push(src);
  int levels = 0;
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    ++levels;
    for (auto dest : table[src]) {
      if (UNDISCOVERED == status[dest]) {
        if (find(H.begin(), H.end(), dest) != H.end()) {
          ++levels;
          break;
        }
        status[dest] = DISCOVERED;
        Q.push(dest);
      }
    }
    status[src] = VISITED;
  }
  return levels - 1;
}

int solution(vector<int> &A, vector<int> &B, int N, vector<int> &H) {
  auto table = createTable(A, B, N);
  auto status = vector<NODE_TYPE>(N, UNDISCOVERED);
  auto levels = numeric_limits<int>::max();
  for (int src = 0; src < table.size(); ++src) {
    levels = min(levels, bfs(table, src, H));
  }
  return levels;
}

int main (void)
{
  vector<int> A = {0, 1, 1, 3};
  vector<int> B = {1, 2, 3, 4};
  vector<int> H = {2, 4};
  int N = 6;
  int res = solution(A, B, N, H);
  printf("%d\n", res);
  return 0;
}
