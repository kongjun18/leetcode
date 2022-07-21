// 1. 递归参数
// 需要传递结果、路径以及子树的根。
//
// 2. 种子条件
// 找到一条路径，即子树根为叶子节点。
//
// 3. 递归逻辑
// 维护从树根到当前递归层的路径。向左右子树递归向下，遇到叶子节点则将路径压入到结果中，
// 回溯，重复以上过程。
class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<int> path;
    vector<string> result;
    travel(root, path, result);
    return result;
  }
  void travel(TreeNode *path, vector<int> &path, vector<string> &result) {
    path.push_back(path->val);
    if (!path->left && !path->right) {
      result.push_back(path2string(path));
      return;
    }
    if (path->left) {
      travel(path->left, path, result);
      path.pop_back();
    }
    if (path->right) {
      travel(path->right, path, result);
      path.pop_back();
    }
  }
  string path2string(const vector<int> &path) {
    if (path.empty()) {
      return "";
    }
    stringstream ss;
    ss << path[0];
    for (int i = 1; i < path.size(); ++i) {
      ss << "->" << path[i];
    }
    string s;
    ss >> s;
    return s;
  }
};
