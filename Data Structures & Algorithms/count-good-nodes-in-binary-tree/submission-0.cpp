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
    multiset<int> mmax;
    int ans = 0;
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        
        if(mmax.empty())
        {
            ans++;
        }
        else
        {
            if(*(mmax.rbegin()) <= root->val) 
            {
                ans++;
            }
            
        }
        mmax.insert(root->val);
        cout<<mmax.size()<<" "<<root->val<<" "<<*(mmax.rbegin())<<" "<<ans<<"\n";
        goodNodes(root->left);
        goodNodes(root->right);
        return ans;
    }
};
