// 难点：
// - 怎样计算宽度？给每个节点分配数组二叉树的节点 id，最左端节点是队列头，
//   最右端是队列尾，每层宽度只需要取这两个节点 id 相减即可。
// - 如何避免数值溢出？id 不用于定位，只用于相减计算宽度，只需要保持同层
//   节点 id 相对偏移即可，所以赋值 id 时让 id 减去最左端 id 以减小数值。
class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {

    queue<pair<TreeNode *, long long>> q;
    if (root)
      q.push({root, 0});
    long long width = 0;
    while (!q.empty()) {
      int size = q.size();
      long long min = INT_MAX, max = 0;
      long long offset = 0;
      for (int i = 0; i < size; ++i) {
        TreeNode *parent = q.front().first;
        auto id = q.front().second;

        // 这里有两种做法，结果是一样的。

        // q.pop();
        // if (i == 0) {
        //   offset = id;
        // }
        // min = std::min(min, id);
        // max = std::max(max, id);
        // width = std::max(width, max - min + 1);

        // if (i == 0) {
        //   offset = id;
        //   width = std::max(width, q.back().second - id + 1);
        // }
        // q.pop();

        if (parent->left) {
          q.push({parent->left, (id - offset) * 2 + 1});
        }
        if (parent->right) {
          q.push({parent->right, (id - offset) * 2 + 2});
        }
      }
    }
    return width;
  }
};
