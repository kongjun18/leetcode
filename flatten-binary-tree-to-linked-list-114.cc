// 姊妹题：
// - convert-binary-search-tree-to-sorted-doubly-linked-list-426
//
// 中序遍历，每次将当前节点添加到链表末尾。注意节点成员的修改！
class Solution {
public:
  void flatten(TreeNode *root) {
    if (root) {
      if (!tail) {
        tail = new TreeNode(-1, nullptr, nullptr);
      }
      tail->right = root;
      TreeNode *right = root->right;
      TreeNode *left = root->left;
      tail->left = nullptr;
      tail->right = root;
      tail = root;
      flatten(left);
      flatten(right);
    }
  }

private:
  TreeNode *tail{nullptr};
};
