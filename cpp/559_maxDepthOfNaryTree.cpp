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
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int child_max = 0;
        for (Node* child: root->children) {
            int curr_child_max = maxDepth(child);
            if (child_max <= curr_child_max) {
                child_max = curr_child_max;
            }
        }
        return 1 + child_max;
    }
};
