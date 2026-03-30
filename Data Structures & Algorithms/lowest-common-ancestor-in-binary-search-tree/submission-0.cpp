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
    unordered_set<int> pAns;
    TreeNode* ans = nullptr;
    void fillAns(TreeNode* root, TreeNode* p)
    {
        if(root->val == p->val)
        {
            pAns.insert(root->val);
            cout<<root->val<<" ";
            return;
        }
        if(root->val < p->val)
        {
            fillAns(root->right, p);
            pAns.insert(root->val);
        }
        else
        {
            fillAns(root->left, p);
            pAns.insert(root->val);
        }
        // cout<<root->val<<" ";
    }
    bool search(TreeNode* root, TreeNode* q)
    {
        // if(root == nullptr) return false;
        // cout<<root->val<<" "<<q->val<<"\n";
        if(q->val == root->val)
        {
            // Lowest Level
            if(pAns.find(q->val) != pAns.end())
            {
                ans = root;
                return true;
            }
            else
                return false;
        }
        if(q->val < root->val)
        {
            if(search(root->left, q)) return true;
        }
        else
        {
            if(search(root->right, q)) return true;

        }
        if(pAns.find(root->val) != pAns.end())
        {
            ans = root;
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fillAns(root, p);
        // cout<<"\n";
        // for (auto it:pAns)
        // cout<<it<<" ";
        search(root, q);
        // return ans;
        return ans;
    }
};
