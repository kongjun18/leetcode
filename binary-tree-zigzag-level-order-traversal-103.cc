// 普通的层次遍历，每一层遍历时，将下一层节点保存下来，下一次从左往右遍
// 历。
//
// zigzag 遍历中，同样将下一层节点保存下来，但下一次 zigzag 交替遍历。
//
// 为了保存下一层节点，对于 zig（从左往右）方向，从左往右 push_back()；
// 对于 zag（从右往左）方向，从右往左，push_front()。
//
// 遍历时，zig 从左往右取（pop_front()），zag 从右往左取（pop_front()）。
//
// 简单的说，普通的层次遍历使用队列，而 zigzag 交替使用队列/栈（使用
// deque 即可）。
//
// 注意：
//     - for 的循环控制变量不是 q.size()！如果用 q.size()，q 的大小在运
//     行中变化，导致循环不是层次遍历。
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    deque<TreeNode *> q;
    if (root) {
      q.push_back(root);
    }
    bool zig = false;
    vector<vector<int>> res;
    while (!q.empty()) {
      TreeNode *node = nullptr;
      vector<int> temp;
      zig = !zig;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        if (zig) {
          node = q.front();
          q.pop_front();
          if (node->left) {
            q.push_back(node->left);
          }
          if (node->right) {
            q.push_back(node->right);
          }
        } else {
          node = q.back();
          q.pop_back();
          if (node->right) {
            q.push_front(node->right);
          }
          if (node->left) {
            q.push_front(node->left);
          }
        }
        temp.push_back(node->val);
      }
      res.push_back(temp);
    }
    return res;
  }
};
