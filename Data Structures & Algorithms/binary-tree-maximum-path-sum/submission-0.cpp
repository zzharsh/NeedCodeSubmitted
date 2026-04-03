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
    int res = -10000;
    int dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        res = max(root->val, res);
        res = max(root->val + leftMax + rightMax, res);
        res = max(root->val + leftMax, res);
        res = max(root->val + rightMax, res);
        int returnVal = max(leftMax, rightMax) + root->val;
        printf("node: %d, res: %d, returnValue: %d \n", root->val, res, returnVal);
        return returnVal;

    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
