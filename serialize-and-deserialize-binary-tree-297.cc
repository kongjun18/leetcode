// 序列化的结果必须能够唯一地对应树的结构，并且要保留足够的重建需要的信息。
//
// 序列化的结果是从前往后写入的，因此先序遍历比较合适。先序遍历的过程中，将节点
// 的值转化为字符串添加到序列化数据末尾，如果节点为 nullptr，用 # 表示。序列化
// 数据中，节点间以空格分隔。
//
// 先序遍历将子树分为 [root] [left tree] [right tree]，[left tree] 的根是它最左
// 边的元素，序列化数据一遍扫描过去，就是一个先序遍历的过程。
//
// 二叉树先序遍历结果区域的性质可以参考
// construct-binary-tree-from-preorder-and-inorder-traversal-105 和
// construct-binary-tree-from-preorder-and-postorder-traversal-889。
//
// 在 C++ 中有一个实现技巧，即 stringstream 以空格分隔，从 stringstream 获取输入
// 时，获取到的输入是一个个以空格分隔开的字符串，这样就不需要自己处理空格。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string ans;
    serializeImpl(root, ans);
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    stringstream ss;
    ss << data;
    return deserializeImpl(ss);
  }

private:
  void serializeImpl(TreeNode *root, string &result) {
    if (root) {
      result.push_back(' ');
      result.append(to_string(root->val));
      serializeImpl(root->left, result);
      serializeImpl(root->right, result);
    } else {
      result.append(" #");
    }
  }
  TreeNode *deserializeImpl(stringstream &ss) {
    string value;
    if (ss >> value) {
      if (value == "#") {
        return nullptr;
      }
      TreeNode *root = new TreeNode(stoi(value));
      root->left = deserializeImpl(ss);
      root->right = deserializeImpl(ss);
      return root;
    }
    return nullptr;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
