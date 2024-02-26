/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void preorder_impl(Node *root, vector<int> &res) {
        if (root) {
            res.push_back(root->val);
            for (const auto child : root->children) {
                preorder_impl(child, res);
            }
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder_impl(root, res);
        return res;
    }
};
