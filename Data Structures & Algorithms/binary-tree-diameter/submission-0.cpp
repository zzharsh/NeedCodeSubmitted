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
    int ans = 0;
    int dfs(TreeNode* root)
    {
        
        if(root->left == nullptr && root->right == nullptr) 
        {
            // cout<<root->val<<" "<<ans<<"\n";
            return 0;
        }
        int l = root->left == nullptr ? -1 : dfs(root->left);
        int r = root->right == nullptr ? -1: dfs(root->right);
        ans = max(ans, l+r+2);
        // cout<<root->val<<" "<<l<<" "<<r<<" "<<ans<<"\n";
        return max(l,r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
