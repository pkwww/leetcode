#include <cstddef>
#include <limits>
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int prev = numeric_limits<int>::min();
        bool first_cmp = true;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (!s.empty() || curr != nullptr) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            TreeNode* node = s.top();
            s.pop();
            if (prev >= node->val && !first_cmp) {
                return false;
            }
            first_cmp = false;
            prev = node->val;
            curr = node->right;
        }
        return true;
    }
};
