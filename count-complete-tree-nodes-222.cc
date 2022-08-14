// 算法流程：
// 1. 计算除最后一层的所有节点数
// 2. 在最后一层的节点编号范围内二分搜索最后一层的最后一个元素编号，得到最后一
//    层元素个数。
// 3. 1、2 步得到的节点数之和即满二叉树节点数。
//
// 树的深度和节点编号从 1 开始计算。
//
// 1. 如何根据编号找到节点
// 对于第 level 层的节点，只看其低 level-1 位，从高往低，0代表左孩子，1代表有孩子。
// 比如节点 5（0101）在第 3 层，只看其低 2 位为 01，因此先往左走再往右走。
//
// 2. 如何获取第 level 层第一个节点的编号
// 第 level 层的第一个节点编号为 2^level。
//
// 3. 如何计算前 level 层的总数
// 对于前 level-1 层，第 level 层节点数为 2^level，因此累加即可。为了实现方便，
// 从第二层开始累加，累加器初始为 1（表示第一层的 1 个节点）。
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int countNodes(TreeNode *root) {
    int level = 0;
    TreeNode *curr = root;
    while (curr) {
      level++;
      curr = curr->left;
    }
    if (level < 2) { // corner case
      return level;
    }

    // 计算最后一层外的节点数
    int nr = 1;
    int count = 1;
    for (int i = 1; i < level - 1; ++i) {
      nr *= 2;
      count += nr;
    }
    nr *= 2; // 最后一层第一个元素
    int start = nr;
    int end = nr + nr - 1;
    while (start <= end) { // 搜索最后一层最后一个元素编号
      int mid = start + (end - start) / 2;
      if (exist(root, level, mid)) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    } // end 为最后一层最后一个元素编号
    return count + (end < nr ? 0 : end - nr +1);
  }

  bool exist(TreeNode *root, int level, int target) { // 0110
    level--;
    while (level--) {
      root = (target & (1 << level)) ? root->right : root->left;
      if (!root) {
        return false;
      }
    }
    return true;
  }
};
