/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool DFS(TreeNode* node, int mn, int mx)
    {
        if(node == nullptr) return true;
        if(node->val > mn && node->val < mx)
        {
            // int nmn = min(mn, node->val);
            // int nmx = max(mx, node->val);
            return DFS(node->left, mn, node->val) && DFS(node->right, node->val, mx);
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return DFS(root, -10001, 10001);
    }
};
