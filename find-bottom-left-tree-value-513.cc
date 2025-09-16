// 1. 层序遍历
//
// 2. DFS
// 优先往左边走，这样在任何一个深度上碰到的第一个 leaf 都是 left-most leaf。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int max_depth;
    int value;
    void findBottomLeftValueImpl(TreeNode *root, int depth) {
        if (root) {
            if (depth+1 > max_depth) {
                max_depth = depth + 1;
                value = root->val;
            }
            if (root->left) {
                findBottomLeftValueImpl(root->left, depth+1);
            }
            if (root->right) {
                findBottomLeftValueImpl(root->right, depth+1);
            }
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        findBottomLeftValueImpl(root, 0);
        return value;
    }
};
