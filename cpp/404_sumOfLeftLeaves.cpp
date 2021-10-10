#include <cstddef>
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
    int help(TreeNode* root, bool isleft) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr && isleft) {
            return root->val;
        }
        int left_sum = help(root->left, true);
        int right_sum = help(root->right, false);
        return left_sum + right_sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return help(root, false);
    }
};
