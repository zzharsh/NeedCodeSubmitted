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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(ans == false) return false;
        if(root->left == nullptr && root->right == nullptr) return true;
        if((root->left != nullptr && root->val > root->left->val) &&
            (root->right != nullptr && root->val < root->right->val))
            {
                return isValidBST(root->left) && isValidBST(root->right);
            }
        else if(root->left == nullptr && root->val < root->right->val)
        {
            return isValidBST(root->right);
        }
        else if(root->right == nullptr && root->val > root->left->val)
        {
            return isValidBST(root->left);
        }
        else
        {
            ans = false;
            return ans;
        }
    }
};
