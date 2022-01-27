#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

// Disjoint set
class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      rank[i] = i;
    }
    for (int i = 0; i < isConnected.size(); ++i)
      for (int j = i + 1; j < isConnected.size(); ++j) {
        if (isConnected[i][j]) {
          if (unionSet(i, j)) {
            --n;
          }
        }
      }
    return n;
  }

private:
  vector<int> parent;
  vector<int> rank;
int find(int x) {
  while (parent[x] != x) {
      x = parent[x];
  }
    return x;
}

bool unionSet(int x, int y) {
  int parentX = find(x);
  int parentY = find(y);
  if (parentX != parentY) {
    if (rank[parentX] < rank[parentY]) {
      parent[parentX] = parentY;
    } else if (rank[parentX] == rank[parentY]) {
      parent[parentY] = parentX;
      ++rank[parentX];
    } else {
      parent[parentY] = parentX;
    }
    return true;
  }
  return false;
}
};

int main (int argc, char *argv[])
{
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    assert ( 2 == Solution{}.findCircleNum(isConnected));

    return 0;
}
