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
    bool ans = true;
    int dfs(TreeNode* root)
    {
        if(ans == false || root == nullptr) return 0;
        int hl = dfs(root->left);
        int hr = dfs(root->right);
        if(abs(hl-hr) > 1)
        {
            ans = false;
            return 0;
        }
        return max(hl, hr) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
