// 姊妹题：
// - construct-binary-tree-from-preorder-and-inorder-traversal-105
// - construct-binary-tree-from-inorder-and-postorder-traversal-106
//
// 后序遍历序列可以分为三部分： [left tree] [right tree] [root]
// 先序遍历序列可以分为三部分： [root] [left tree] [right tree]
//
// 显然，只要得到后序遍历或先序遍历的序列，就可以得到该子树的根节点，只需要在其
// 左、右子树中递归，就可以不断获取到子树的左、右子树根节点，进而重构整棵树。
//
// 但是，单独的先序遍历或后序遍历都无法直接获取到左、右子树区域，因此问题的关键
// 在于如何寻找左右子树区域的分界点，找到分界点就可以递归地搜索子树根节点。
//
// 前、序遍历的结果只是次序不同，每个区域的元素是相同的（因为是同一子树）。先序
// 遍历的 [left tree] 的根节点是其左边界节点，这个节点在后序遍历的 [left tree]
// 右边界，这样就找到了左、右子树区域分界点。
//
// 在左、右子树中递归地执行以上过程就可以重构整棵树。
//
// 陷阱：根据先序遍历序列 [left tree] 左边界确定后序遍历左右子树分界点，根据后序
//       遍历序列 [right tree] 右边界确定先序序列左右子树分界点，导致结果错误。
//
//       一种边界情况是，先序遍历序列为 [root] [left tree]，但是后序遍历中按照上
//       面的方法总是认为 [root] 左边的元素是 [right tree] 的根，从先序遍历的视
//       角看不存在 [right tree]，但是从后序遍历的视角看存在 [right tree]，导致错误。
//
//       一个例子是注释中的代码。
class Solution {
public:
  TreeNode *constructFromPrePost(vector<int> &preorder,
                                 vector<int> &postorder) {
    return constructFromPrePostImpl(preorder.cbegin(), preorder.cend(),
                                    postorder.cbegin(), postorder.cend());
  }

private:
  template <typename Iter>
  TreeNode *constructFromPrePostImpl(Iter preorder_start, Iter preorser_end,
                                     Iter postorder_start, Iter postorder_end) {
    if (distance(preorder_start, preorser_end) <= 0) { // 无节点
      return nullptr;
    } else if (distance(preorder_start, preorser_end) == 1) { // 一个节点
      return new TreeNode(*preorder_start);
    }
    const auto root_value = *preorder_start;
    const auto left_value = *(preorder_start + 1);
    // preorder: [preorder_start+1, preorder_pivot) [preorder_pivot,
    // preorser_end)
    // postorder: [postorder_start, postorder_pivot+1) [ postorder_pivot+1,
    // postorder_end-1)
    const auto postorder_pivot =
        find(postorder_start, postorder_end, left_value) + 1;

    const auto preorder_pivot =
        preorder_start + 1 + distance(postorder_start, postorder_pivot);
    const auto left = constructFromPrePostImpl(
        preorder_start + 1, preorder_pivot, postorder_start, postorder_pivot);
    auto right = constructFromPrePostImpl(preorder_pivot, preorser_end,
                                          postorder_pivot, postorder_end - 1);
    return new TreeNode(root_value, left, right);
  }
  // template <typename Iter>
  // TreeNode *constructFromPrePostImpl(Iter preorder_start, Iter preorser_end,
  //                                    Iter postorder_start, Iter
  //                                    postorder_end) {
  //   if (distance(preorder_start, preorser_end) <= 0) { // 无节点
  //     return nullptr;
  //   } else if (distance(preorder_start, preorser_end) == 1) { // 一个节点
  //     return new TreeNode(*preorder_start);
  //   } else if (distance(preorder_start, preorser_end) == 2) { // 两个节点
  //     return new TreeNode(*preorder_start, new TreeNode(*(preorder_start +
  //     1)), nullptr);
  //   }
  //   const auto root_value = *preorder_start;
  //   const auto left_value = *(preorder_start + 1);
  //   const auto right_value = *(preorser_end - 2);
  //   // preorder: [preorder_start+1, preorder_pivot) [preorder_pivot,
  //   // preorser_end)
  //   // postorder: [postorder_start, postorder_pivot+1) [ postorder_pivot+1,
  //   // postorder_end-1)
  //   const auto preorder_pivot = find(preorder_start, preorser_end,
  //   right_value); const auto postorder_pivot =
  //       find(postorder_start, postorder_end, left_value);
  //   const auto left =
  //       constructFromPrePostImpl(preorder_start + 1, preorder_pivot,
  //                                postorder_start, postorder_pivot + 1);
  //   auto right = constructFromPrePostImpl(
  //       preorder_pivot, preorser_end, postorder_pivot + 1, postorder_end -
  //       1);
  //   return new TreeNode(root_value, left, right);
  // }
};
