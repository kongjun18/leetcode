class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    pathSumImpl(root, targetSum);
    return paths;
  }

private:
  void pathSumImpl(TreeNode *root, int targetSum) {
    if (!root) {
      return;
    }
    path.push_back(root->val);
    if (!root->left && !root->right && root->val == targetSum) {
      paths.push_back(path);
    }
    if (root->left) {
      pathSumImpl(root->left, targetSum - root->val);
      path.pop_back();
    }
    if (root->right) {
      pathSumImpl(root->right, targetSum - root->val);
      path.pop_back();
    }
  }

private:
  vector<int> path;
  vector<vector<int>> paths;
};
