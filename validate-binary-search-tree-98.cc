// 二叉搜索树的左子树的值小于当前节点，右子树的值大于当前节点。
// 即对于每个子树，左子树树根必定小于父亲，右子树必定大于父亲。
// 从上往下递归判断每个子树树根是否符合条件即可。
//
// 错误思路：查找左子树最大值和右子树最小值和根节点比较。
class Solution {
public:
    bool helper(TreeNode* root, long long left, long long right) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= left || root -> val >= right) {
            return false;
        }
        return helper(root -> left, left, root -> val) && helper(root -> right, root -> val, right);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

