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
    int cnt = 0;
    int res = -1;
    int kt = -1;
    void preorder(TreeNode* root)
    {
        if(root == nullptr) return;
        preorder(root->left);
        cnt++;
        if(cnt == kt)
        {
            res = root->val;
            return;
        }
        preorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        kt = k;
        preorder(root);
        return res;
    }
};
