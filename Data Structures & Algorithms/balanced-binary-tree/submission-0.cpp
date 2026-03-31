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
    int height(TreeNode* node)
    {
        if(node == nullptr) return 0;
        return (max(height(node->left) , height(node->right)) +1);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        cout<<root->val<<"\n";
        if (root->left != nullptr && 
            isBalanced(root->left) &&
            root->right != nullptr &&
            isBalanced(root->right)) return true;
        int h1 = height(root->left);
        int h2 = height(root->right);
        cout<<root->val<<" "<<h1<<" "<<h2<<"\n";
        return abs(h1 - h2) < 2;
    }
};
