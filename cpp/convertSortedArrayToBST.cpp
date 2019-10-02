#include <cstddef>
#include <vector>
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
    TreeNode* helper(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        if (mid >= end) {
            return nullptr;
        }
        TreeNode* left = helper(nums, start, mid);
        TreeNode* right = helper(nums, mid+1, end);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = left;
        root->right = right;
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size();
        return helper(nums, start, end);
    }
};
