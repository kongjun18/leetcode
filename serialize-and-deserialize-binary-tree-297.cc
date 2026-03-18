// 序列化的结果必须能够唯一地对应树的结构，并且要保留足够的重建需要的信息。
//
// 1. 先序遍历
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
// 2. 层序遍历
//
// 按层序列化节点，用 # 标示一层的结束。反序列化时，按层创建节点，并记录上一层节点。
// 当本层节点创建完毕后，更新上一层节点（父亲）的左右孩子。
//
//
// 实现
// - 在 C++ 中有一个实现技巧，即 stringstream 以空格分隔，从 stringstream 获取输入
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
private:
    void append(string &serialized, const TreeNode *node) {
        if (!serialized.empty()) {
            serialized.push_back(' ');
        }
        if (node) {
            serialized += to_string(node->val);
        } else {
            serialized += "null";
        }
    }
    void end_level(string &serialized) {
        if (!serialized.empty()) {
            serialized += " ";
        }
        serialized += "#";
    }

    TreeNode *create_node(const string &word) {
        if (word == "null") {
            return nullptr;
        }
        return new TreeNode(stoi(word));
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string serialized;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> curr_level;
            for (int i = 0; i < size; i++) {
                auto node = q.front(); q.pop();
                append(serialized, node);

                // 最后一层会把下面的空节点压入序列化数据中
                if (!node) {
                    continue;
                }
                q.push(node->left);
                q.push(node->right);
            }
            end_level(serialized);
            cout << serialized << endl;
        }
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream iss(data);
        string word;
        vector<TreeNode*> prev_level;
        vector<TreeNode*> curr_level;
        int level = 0;
        TreeNode* root;
        while (iss >> word) {
            if (word != "#") {
                auto node = create_node(word);
                curr_level.push_back(node);
            } else { // end of a level
                for (int i = 0; i < curr_level.size(); i++) {
                    int parent = i/2;
                    TreeNode *node = curr_level[i];
                    if (parent < prev_level.size()) {
                        if (i%2==0) {
                            prev_level[parent]->left = node;
                        } else {
                            prev_level[parent]->right = node;
                        }
                    }
                }

                if (level == 0) {
                    root = curr_level.front();
                }

                prev_level.clear();
                // 要考虑当前层次是 null 的情况：最后一层节点的空孩子。
                for (TreeNode *node : curr_level) {
                    if (node) {
                        prev_level.push_back(node);
                    }
                }
                curr_level.clear();
                level++;
            }
        }
        return root;
    }
};
