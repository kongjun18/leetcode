// inorder: [left] root [right]
// postorder: [left] [right] root
//
// For soly inorder traversal result, it is impossible to restore the tree as
// we cannot determine the root position. For soly postorder, we can determine
// the root position since the root is at the end of postorder, but we
// cannot partition left and right sub-trees.
//
// For an inorder sub-tree traversal result, we can get the root position using
// postorder as all nodes are distinctive. If the root position of inorder traversal
// is determined, go to the left/right sub-tree and repeat the procedure.
class Solution {
private:
    // IMPORTANT: post_end must be a reference, or else the current backtracking
    // level uses outdated post_end.
    TreeNode* buildTreeImpl(vector<int> &inorder, int in_start, int in_end, vector<int> &postorder, int &post_end) {

        int val = postorder[post_end];
        int pos = std::find(inorder.cbegin()+in_start, inorder.cbegin()+in_end+1, val) - inorder.cbegin();

        TreeNode *root = new TreeNode(val, nullptr, nullptr);

        // No right sub-tree
        if (pos < in_end) {
            post_end--;
            root->right = buildTreeImpl(inorder, pos+1, in_end, postorder, post_end);
        }

        // No left sub-tree
        if (pos > in_start) {
            post_end--;
            root->left = buildTreeImpl(inorder, in_start, pos-1, postorder, post_end);
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post_end = postorder.size()-1;
        return buildTreeImpl(inorder, 0, inorder.size()-1, postorder, post_end);
    }
};
