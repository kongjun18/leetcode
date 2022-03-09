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

// class Solution {
// public:
//   vector<int> preorderTraversal(TreeNode *root) {
//     vector<int> result;
//     TreeNode *curr = root;
//     stack<TreeNode *> s;
//     while (1) {
//       while (curr) {
//         result.push_back(curr->val);
//         if (curr->right) {
//           s.push(curr->right);
//         }
//         curr = curr->left;
//       }
//       if (s.empty()) {
//         break;
//       }
//       curr = s.top();
//       s.pop();
//     }
//     return result;
//   }
// };

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    TreeNode *curr = root;
    stack<TreeNode *> s;
    while (curr || !s.empty()) {
      if (curr) { // 一直往左边走
        result.push_back(curr->val);
        if (curr->right) {
          s.push(curr->right);
        }
        curr = curr->left;
      } else { // 控制遍历方向
        curr = s.top();
        s.pop();
      }
    }
    return result;
  }
};
