// 找到最小公共祖先的两种情况：
// 1) 在左右子树中找到了 p 和 q。
// 2) 在一个子树中找到了 p 或 q，并且根节点为另一个 p 或 q。
//
// 递归函数设计：
// 1. 参数和返回值
//     lowestCommonAncestor() 返回查找到的节点。
// 2. 终止条件
//     当前节点为空，表示此边无目标节点，返回 nullptr。
// 3. 单层逻辑
//     - 查找到最小公共祖先：
//         1) 左右子树都查找到目标节点，则此节点是最近祖先，返回当前节点。
//         2) 当前节点是目标节点，则此节点要么是祖先，要么只是目标节点，返回当前节点。
//     - 未查找到公共子树：
//         1) 如果只有左子树查找到目标节点，则回溯传递做子树目标节点，返回左子树目标节点。
//         2) 如果只有右子树查找到目标节点，则回溯传递做子树目标节点，返回右子树目标节点。
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
