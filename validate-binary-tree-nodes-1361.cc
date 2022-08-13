// 合法的二叉树符合以下几个条件：
// 1. 只有一个根节点
// 2. 根节点没有父亲
// 3. 每个节点最多右两个孩子
// 4. 一个节点有且只有一个父亲
// 5. 存在根节点到其他所有节点的路径
//
// 二叉树是一种特殊的图，直接 DFS/BFS 即可。
//
// 算法流程：
// 1. 找到根节点（入度为 0），找不到意味着不是合法的树。
// 2. 从根节点遍历（DFS/BFS），如果找到访问过的节点，意味着出现环路或者一个节点
//    右两个父亲。
// 3. 查看是否所有节点都访问过，存在未访问过的节点说明此图有多个联通子图，即存在
//    游离在树外的节点。
//
class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    vector<int> indegree(n);
    auto addIndegree = [&](const int i) {
      if (i != -1) {
        indegree[i]++;
      }
    };
    for_each(leftChild.cbegin(), leftChild.cend(), addIndegree);
    for_each(rightChild.cbegin(), rightChild.cend(), addIndegree);
    const int root = distance(indegree.cbegin(),
                              find(indegree.cbegin(), indegree.cend(), 0));
    if (root >= n) { // 找不到根节点
      return false;
    }
    unordered_set<int> visted;
    queue<int> q;
    q.push(root);
    auto processChild = [&](const int child) {
      if (child != -1) {
        if (visted.count(child)) { // 环路或节点有多个父亲
          return false;
        }
        visted.insert(child);
        q.push(child);
      }
      return true;
    };
    while (!q.empty()) {
      const auto node = q.front();
      q.pop();
      visted.insert(node);
      if (!processChild(leftChild[node])) {
        return false;
      }
      if (!processChild(rightChild[node])) {
        return false;
      }
    }
    return visted.size() == indegree.size(); // 是否存在游离节点
  }
};
