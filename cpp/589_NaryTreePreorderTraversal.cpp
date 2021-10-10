#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    void preorder_help(Node* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        v.push_back(root->val);
        for (Node* child: root->children) {
            preorder_help(child, v);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res = {};
        preorder_help(root, res);
        return res;
    }
};
