// 先序遍历，以此节点为根和另一颗树对比，知道查找到相同子树。
//
// 判断两子树递归即可，如果两子树根节点相同，则判断左右子树是否相同，否则两子树
// 不相同。
//
// 实现时要注意先序遍历和判断子树相等的逻辑，尤其是要避免访问空指针。
class Solution {
public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    return dfs(root, subRoot);
  }

private:
  bool isSame(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) {
      return true;
    }
    if (root1 && !root2 || !root1 && root2 || root1->val != root2->val) {
      return false;
    }
    return isSame(root1->left, root2->left) &&
           isSame(root1->right, root2->right);
  }
  bool dfs(TreeNode *root, TreeNode *subRoot) {
    if (!isSame(root, subRoot)) {
      if (root) {
        return dfs(root->left, subRoot) || dfs(root->right, subRoot);
      }
      return false;
    }
    return true;
  }
};
