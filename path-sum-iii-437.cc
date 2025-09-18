// 遍历所有节点，记录 root 到当前节点的路径，每次遍历节点的时候判断当前路径是否符合条件。
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
    vector<int> path;
    int result = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root) {
            path.push_back(root->val);
            long long sum = 0;
            for (int i = path.size()-1; i >= 0; i--) {
                sum += path[i];
                if (sum == targetSum) {
                    result++;
                }
            }
            int depth = path.size();
            if (root->left) {
                pathSum(root->left, targetSum);
                path.resize(depth);
            }
            if (root->right) {
                pathSum(root->right, targetSum);
                path.resize(depth);
            }
        }
        return result;
    }
};

