// 递归函数设计：
// 1. 参数和返回值
//     lowestCommonAncestor() 返回查找到的节点或最近祖先。
// 2. 终止条件
//     当前节点为空，表示此边无目标节点，返回 nullptr。
// 3. 单层逻辑
//    1) 当前节点不是目标节点
//         1) 左右子树都查找到目标节点，则此节点是最近祖先，返回当前节点。
//         2) 左子树查找到目标节点，则返回该目标节点。
//         3) 右子树查找到目标节点，则返回该目标节点。
//    2) 当前节点是目标节点
//       需要判断当前节点是最近祖先还是只是找到了目标节点，这里使用的是后序遍历，
//       遍历到当前节点时，孩子节点已经遍历过，子树中是否有另一个目标节点有两种
//       情况：
//         1) 查找到另一个目标节点：当前节点即最近祖先，返回该节点。
//         2) 未查到另一个目标节点：当前节点是目标节点，返回该节点。
//       子树中查找到另一个目标节点时，返回值自然从“目标节点”变成了“最近祖先”。
//
// 两个目标节点一定在树中，因此不需要考虑只有一个节点的情况，找到最小公共祖先有
// 两种情况：
// 1) 在左右子树中找到了 p 和 q。
// 2) 在一个子树中找到了 p 或 q，并且根节点为另一个 p 或 q。
//
// 因此，在 lowestCommonAncestor() 回溯返回后，返回值一定是最近祖先；在没回溯完
// 前，lowestCommonAncestor() 返回值是最近祖先或目标节点，但最近祖先一定是返回值。
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    // 1. 两子树找到目标节点，当前节点是最近祖先。
    // 2. 当前节点是目标节点，返回该节点。回溯时覆盖子树中找到的目标节点，如果
    //    一个目标节点是另一个目标节点的孩子，最后回溯完这个节点就是最近祖先。
    if (left && right || root == q || root == p) {
      return root;
    } else if (left) {
      return left;
    } else if (right) {
      return right;
    }
    return nullptr;
  }
};

// DFS
//
// pre-order traversal searchers for q and q. The lowest common ancester is
// either:
// - q and q are in the left and right sub-tree.
// - root is p/q and other target node resides in it's sub-tree.
//
// The return value indicates whether the target node is found. Since all nodes
// have different values, it is no necessary to differeciate q and p.
class Solution {
    TreeNode *lca{NULL};
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return false;
        }
        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);

        if (left && right) {
            lca = root;
        }
        if ((left || right) && (root->val == p->val || root->val == q->val)) {
            lca = root;
        }
        return left || right || (root->val == p->val) || root->val == q->val;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       dfs(root, p, q);
       return lca;

    }
};
