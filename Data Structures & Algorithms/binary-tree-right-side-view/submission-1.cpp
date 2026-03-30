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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> Q1, Q2;
        vector<int> ans;
        Q1.push(root);
        while(!Q1.empty())
        {
            TreeNode* temp = Q1.front();
            ans.push_back(temp->val);
            while(!Q1.empty())
            {
                temp = Q1.front();
                if(temp->right != nullptr) Q2.push(temp->right);
                if(temp->left != nullptr) Q2.push(temp->left);
                Q1.pop();
            }
            Q1 = Q2;
            Q2 = queue<TreeNode*>();
        }
        return ans;
        // while(temp!=nullptr)
    }
};
