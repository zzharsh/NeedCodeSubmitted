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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> Q1, Q2;
        Q1.push(root);
        while(!Q1.empty())
        {
            vector<int> tempAns;
            while(!Q1.empty())
            {
                TreeNode* temp = Q1.front();
                tempAns.push_back(temp->val);
                if(temp->left != nullptr) Q2.push(temp->left);
                if(temp->right != nullptr) Q2.push(temp->right);
                Q1.pop();
            }
            ans.push_back(tempAns);
            Q1 = Q2;
            Q2 = queue<TreeNode*>();         
        }
        return ans;
    }
};
