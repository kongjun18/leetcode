// 注意区间的分割：
// 1. 可能出现区间为 0 的情况，比如 [2,1] [2,1]。
// 2. 注意区间的变化，第 24、25 行。
// 3. 注意维持前置条件（区间最小为 1），否则迭代器越界。
class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (postorder.empty() || inorder.empty()) {
      return nullptr;
    }
    return buildTreeImpl(inorder.cbegin(), inorder.cend(), postorder.cbegin(),
                         postorder.cend());
  }

private:
  template <typename Iter>
  TreeNode *buildTreeImpl(Iter inorder_begin, Iter inorder_end,
                          Iter postorder_start, Iter postorder_end) {
    if (distance(inorder_begin, inorder_end) == 1) {
      return new TreeNode(*inorder_begin);
    } else if (distance(inorder_begin, inorder_end) == 0) { // 小心区间为 0
      return nullptr;
    }
    auto value = *(postorder_end - 1);
    auto inorder_privot = find(inorder_begin, inorder_end, value);
    auto postorder_privot =
        postorder_start + distance(inorder_begin, inorder_privot);
    auto left = buildTreeImpl(inorder_begin, inorder_privot, postorder_start,
                              postorder_privot);
    auto right = buildTreeImpl(inorder_privot + 1, inorder_end,
                               postorder_privot, postorder_end - 1);
    return new TreeNode(value, left, right);
  }
};
