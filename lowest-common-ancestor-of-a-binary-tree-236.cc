// 1. 参数和返回值
//     lowestCommonAncestor() 返回查找到的节点（目标节点或祖先）。
// 2. 终止条件
//     当前节点为空，表示此边无目标节点，返回 nullptr。
// 3. 单层逻辑
//     - 左右子树都查找到目标节点，则此节点是最近祖先，返回当前节点。
//     - 当前节点是目标节点，则此节点要么是祖先，要么只是目标节点，返回当前节点。
//     - 如果只有左子树查找到目标节点，则回溯传递做子树目标节点，返回左子树目标节点。
//     - 如果只有右子树查找到目标节点，则回溯传递做子树目标节点，返回右子树目标节点。
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right || root == q || root == p) {
      return root;
    } else if (left) {
      return left;
    } else if (right) {
      return right;
    }
    return nullptr;
  }
};
