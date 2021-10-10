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
    int curr_sum = 0;
    void helper(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        helper(root->right);
        curr_sum += root->val;
        root->val = curr_sum;
        helper(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
};
