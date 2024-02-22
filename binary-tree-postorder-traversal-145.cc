/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x,j TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 迭代式后序遍历难点：
// - 避免重复压栈。如果将当前节点和右节点压栈，那么进入到下一层时，当前节点可能
//   是之前的右孩子，导致重复压栈。按层处理，每层考虑将左右子树压栈。
// - 避免重复遍历。栈顶元素是父亲，导致出栈后继续遍历导致重复遍历死循环。回溯时
//   判断栈顶元素是父亲还是右兄弟，只在栈顶是右兄弟时跳转到右兄弟继续遍历。
// - 何时回溯。当栈顶是父亲时回溯。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *curr = root;
        vector<int> res;
        if (root) {
            s.push(root);
        }
        while (curr || !s.empty()) {
            if (curr) {
                TreeNode *next = nullptr;
                if (curr->right) {
                    s.push(curr->right);
                    next = curr->right;
                }
                if (curr->left) {
                    s.push(curr->left);
                    next = curr->left;
                }
                curr = next;
            } else {
                curr = s.top();
                s.pop();
                res.push_back(curr->val);
                // 往右走
                // 栈顶要么是父亲，要么是兄弟。通过栈顶判断是否存在右兄弟。
                if (!s.empty() && (s.top()->left != curr) && (s.top()->right != curr)) {
                    // curr 不会进栈，因此不能 pop
                   curr = s.top();
                // 回溯
                } else {
                    curr = nullptr;
                }
            }
        }
        return res;
    }
};

// 栈顶要么是不可用推进的点（访问节点的时机），要么是可以继续推进的点（右兄弟）。
// 先通过栈推进到无法推进（栈顶是父亲），弹出栈顶并访问。
class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    TreeNode *curr = root;
    vector<int> result;
    stack<TreeNode *> s;
    if (root)
      s.push(root);
    while (!s.empty()) {
      // 栈顶不是父亲，可以推进
      if (curr != s.top()->left && curr != s.top()->right) {
        // 这里控制往左还是往右推进
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
      // 推进到了无法推进，访问！
      curr = s.top();
      s.pop();
      result.push_back(curr->val);
    }
    return result;
  }
};
