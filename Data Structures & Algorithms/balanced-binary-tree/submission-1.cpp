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
    int height(TreeNode* node)
    {
        if(node == nullptr) return 0;
        if(ans == false) return 0;
        int hl = height(node->left);
        int hr = height(node->right);
        int hn = max(hl, hr) + 1;
        if(abs(hr-hl) > 1)
        {
            ans = false;
            return 0;
        }
        return hn;
        // return (max(height(node->left) , height(node->right)) +1);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        height(root);
        return ans;
        // cout<<root->val<<"\n";
        // if (root->left != nullptr && 
        //     isBalanced(root->left) &&
        //     root->right != nullptr &&
        //     isBalanced(root->right)) return true;
        // cout<<root->val<<" "<<h1<<" "<<h2<<"\n";
        // return abs(h1 - h2) < 2;
    }
};
