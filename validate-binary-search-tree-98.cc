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

