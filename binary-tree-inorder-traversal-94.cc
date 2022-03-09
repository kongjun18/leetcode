/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// class Solution {
// public:
//   vector<int> inorderTraversal(TreeNode *root) {
//     TreeNode *curr = root;
//     stack<TreeNode *> s;
//     vector<int> result;
//     while (1) {
//       while (curr) {
//         s.push(curr);
//         curr = curr->left;
//       }
//       if (s.empty()) {break;}
//       curr = s.top();
//       s.pop();
//       result.push_back(curr->val);
//       curr = curr->right;
//     }
//     return result;
//   }
// };
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    TreeNode *curr = root;
    stack<TreeNode *> s;
    vector<int> result;
    while (curr || !s.empty()) {
      if (curr) {
        s.push(curr);
        curr = curr->left;
      } else {
        curr = s.top();
        s.pop();
        result.push_back(curr->val);
        curr = curr->right;
      }
    }
    return result;
  }
};
