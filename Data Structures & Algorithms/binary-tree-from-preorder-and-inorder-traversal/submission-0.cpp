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
    vector<int> in, pre;
    int n;
    TreeNode* Build(int si, int ei, int sp, int ep)
    {
        if ((si < 0 || sp < 0 || ei >= n || ep >= n) ||
            (si > ei || sp > ep))
        {
            printf("null %d, %d, %d, %d \n", si, ei, sp, ep);
            return nullptr;
        }
        printf(" %d, %d, %d, %d \n", si, ei, sp, ep);
        TreeNode* root = new TreeNode(pre[sp]);
        if(si == ei)
        {
            return root;
        }
        int mid = si;
        for(int i = si; i <= ei; ++i)
        {
            if(root->val == in[i])
            {
                mid = i;
            }
        }
        mid = mid - si;
        printf("left ");
        root->left = Build(si, si + mid-1, sp+1, sp+mid);
        printf("right ");
        root->right = Build(si + mid+1, ei, sp+mid+1, ep);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        in  = move(inorder);
        pre = move(preorder);
        n = pre.size();

        // return Build(0, )
        return Build(0, n-1, 0, n-1);
    }
};
