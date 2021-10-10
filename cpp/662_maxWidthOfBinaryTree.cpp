#include <cstddef>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBTArray(const vector<TreeNode*>& nodes, int max_height) {
        int max_width = 1;
        for (int h = 0; h < max_height; h++) {
            int start_i = (1 << h) - 1;
            int end_i = (1 << (h+1)) - 1;
            int start = end_i;
            int end = start_i;
            for (int i = start_i; i < end_i; i++) {
                if (nodes[i] != nullptr) {
                    start = i;
                    break;
                }
            }
            for (int i = end_i-1; i >= start_i; i--) {
                if (nodes[i] != nullptr) {
                    end = i;
                    break;
                }
            }
            int level_width = end - start + 1;
            max_width = max(level_width, max_width);
        }
        return max_width;
    }
    int treeHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }
    void build(vector<TreeNode*>& nodes, TreeNode* root, int i) {
        if (root == nullptr) {
            return;
        }
        nodes[i] = root;
        build(nodes, root->left, 2*i+1);
        build(nodes, root->right, 2*i+2);
    }
    
    int bfs(TreeNode* root) {
        int max_w = 1;
        queue<pair<unsigned long long, TreeNode*>> q{};
        q.push({0, root});
        while (!q.empty()) {
            int w = q.back().first - q.front().first + 1;
            max_w = max(max_w, w);
            int size = q.size();
            for (int j = 0; j < size; j++) {
                auto [i, node] = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push({2*i+1, node->left});
                if (node->right != nullptr)
                    q.push({2*i+2, node->right});
            }
        }
        return max_w;
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        // int height = treeHeight(root);
        // vector<TreeNode*> nodes((1 << height) - 1, nullptr);
        // build(nodes, root, 0);
        // return widthOfBTArray(nodes, height);
    }
};
