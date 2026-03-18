// 递归函数设计：
// 1. 参数和返回值
//     lowestCommonAncestor() 返回查找到的节点或最近祖先。
// 2. 终止条件
//     当前节点为空，表示此边无目标节点，返回 nullptr。
// 3. 单层逻辑
//
// 两个目标节点一定在树中，因此不需要考虑只有一个节点的情况，找到最小公共祖先有
// 两种情况：
// 1) 在左右子树中找到了 p 和 q。
// 2) 在一个子树中找到了 p 或 q，并且根节点为另一个 p 或 q。
//
// 由于存在这两种情况，使用后续遍历，处理完左右子树才直到属于哪种情况。根据情况做处理，
// 向上层传递状态。

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (root == p || root == q) {
           return root;
        }

        if (left && right) {
            return root;
        }

        if (left) {
            return left;
        }
        if (right) {
            return right;
        }

        return nullptr;
    }
};
