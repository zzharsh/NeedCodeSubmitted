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
    bool subTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root==nullptr && subRoot == nullptr) return true;
        if(root==nullptr) return false;
        if(subRoot == nullptr) return false;
        if(root->val == subRoot->val)
        {
            return (subTree(root->left, subRoot->left) &&
                    subTree(root->right, subRoot->right));
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr) return false;
        if(subRoot == nullptr) return false;
    
        if(subTree(root, subRoot) == true)
        {
            return true;
        }
        else
        {
            bool left = isSubtree(root->left, subRoot);
            bool right = isSubtree(root->right, subRoot);
            return left || right;
        }
    }
};
