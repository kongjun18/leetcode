// 层次遍历、前序遍历、后续遍历都可以！
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root) {
      invertTree(root->left);
      invertTree(root->right);
      swap(root->left, root->right);
    }
    return root;
  }
};
