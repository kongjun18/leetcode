// 对二叉搜索树中序遍历得到有序序列，将二叉搜索树转化为双向链表实际上就是按照
// 中序遍历的结果构造二分搜索树，中序遍历的过程中，左节点使用后就不会再使用，直
// 接将左孩子作为链表节点的 prev，右孩子作为链表节点的 next 即可。
//
// convert-binary-search-tree-to-sorted-doubly-linked-list-426 是 Leetcode 付费
// 题目，《剑指 Offer》36 题相同，因此这里直接使用《剑指 Offer》36 题，即
// er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof-2048。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
  Node *treeToDoublyList(Node *root) {
    Node *head = new Node(-1, nullptr, nullptr);
    Node *tail = new Node(-1, head, head);
    head->right = tail;
    head->left = tail;
    inorder(root, tail);
    if (tail->left == head) {
      return nullptr;
    }
    head->right->left = tail->left;
    tail->left->right = head->right;
    return head->right;
  }

private:
  void inorder(Node *root, Node *&tail) {
    if (root) {
      inorder(root->left, tail);
      Node *tmp = tail->left;
      tail->left = root;
      Node *right = root->right;
      root->right = tail->right;
      tmp->right = root;
      root->left = tmp;
      inorder(right, tail);
    }
  }
};
