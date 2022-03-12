// See construct-binary-tree-from-inorder-and-postorder-traversal-106.cc
class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTreeImpl(preorder.cbegin(), preorder.cend(), inorder.cbegin(),
                         inorder.cend());
  }

private:
  template <typename Iter>
  TreeNode *buildTreeImpl(Iter preorder_start, Iter preorder_end,
                          Iter inorder_start, Iter inorder_end) {
    if (distance(inorder_start, inorder_end) == 1) {
      return new TreeNode(*inorder_start);
    } else if (distance(inorder_start, inorder_end) == 0) {
      return nullptr;
    }

    auto value = *preorder_start;
    auto inorder_privot = find(inorder_start, inorder_end, value);
    auto preorder_privot =
        preorder_start + 1 + distance(inorder_start, inorder_privot);
    auto left = buildTreeImpl(preorder_start + 1, preorder_privot,
                              inorder_start, inorder_privot);
    auto right = buildTreeImpl(preorder_privot, preorder_end,
                               inorder_privot + 1, inorder_end);
    return new TreeNode(value, left, right);
  }
};
