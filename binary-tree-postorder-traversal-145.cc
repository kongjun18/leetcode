/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x,j TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// 迭代式后序遍历难点：
// - 避免重复压栈。如果将当前节点和右节点压栈，那么进入到下一层时，当前节点可能
//   是之前的右孩子，导致重复压栈。按层处理，每层考虑将左右子树压栈。
// - 避免重复遍历。栈顶元素是父亲，导致出栈后继续遍历导致重复遍历死循环。回溯时
//   判断栈顶元素是父亲还是右兄弟，只在栈顶是右兄弟时跳转到右兄弟继续遍历。

// class Solution {
// public:
//   vector<int> postorderTraversal(TreeNode *root) {
//     TreeNode *curr = root;
//     vector<int> result;
//     stack<TreeNode *> s;
//     if (root)
//       s.push(root);
//     while (curr || !s.empty()) {
//       if (curr) {
//         if (curr->left) {
//           if (curr->right) {
//             s.push(curr->right);
//           }
//           s.push(curr->left);
//           curr = curr->left;
//         } else {
//           if (curr->right) {
//             s.push(curr->right);
//           }
//           curr = curr->right;
//         }
//       } else {
//         curr = s.top(); // 栈顶是可处理的节点
//         s.pop();
//         result.push_back(curr->val);
//         // 如果堆栈非空，回溯。栈顶可能是右兄弟也可能是父亲。
//         // 如果是父亲，意味着父亲节点的孩子都已经处理完了，处理父亲节点，置空 curr（避免再次遍历）。
//         // 如果是右兄弟，跳到右兄弟中继续遍历。
//         if (!s.empty() && curr != s.top()->left && curr != s.top()->right) {
//           curr = s.top();
//         } else {
//           curr = nullptr;
//         }
//       }
//     }
//     return result;
//   }
// };


class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    TreeNode *curr = root;
    vector<int> result;
    stack<TreeNode *> s;
    if (root)
      s.push(root);
    while (!s.empty()) {
      if (curr != s.top()->left && curr != s.top()->right) {
        while (curr = s.top()) {
          if (curr->left) {
            if (curr->right) {
              s.push(curr->right);
            }
            s.push(curr->left);
          } else {
            s.push(curr->right);
          }
        }
        s.pop(); // remove NULL node
      }
      curr = s.top();
      s.pop();
      result.push_back(curr->val);
    }
    return result;
  }
};
