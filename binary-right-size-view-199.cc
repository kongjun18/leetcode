// 层序遍历，记录每层最右边的元素。
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        queue<TreeNode*> q;
        vector<int> res;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (i == size-1) {
                    res.push_back(node->val);
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return res;
    }
};
