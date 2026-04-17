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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> Q1, Q2;
        Q1.push(root);
        if(root != nullptr)
        {
            Q2.push(root);
        }
        while(!Q2.empty())
        {
            if(Q1.front() == nullptr)
            {
                Q1.push(nullptr);
                Q1.push(nullptr);
                res = res + "n" + "," ;
                Q1.pop();
            }
            else
            {
                res = res + to_string(Q1.front()->val) + ",";
                if(Q1.front()->left != nullptr)
                {
                    // printf("pushing %d to Q2\n", Q1.front()->left->val);
                    Q2.push(Q1.front()->left);
                }
                if(Q1.front()->right != nullptr)
                {
                    // printf("pushing %d to Q2\n", Q1.front()->right->val);
                    Q2.push(Q1.front()->right);
                }
                Q1.push(Q1.front()->left);
                Q1.push(Q1.front()->right);
                Q1.pop();
                Q2.pop();
                // cout<<(!Q2.empty())<<endl;
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    bool parse(string data, int& i, int& n, int& rint)
    {
        // printf("i = %d n = %d \n", i,n);

        if(i + 1 >= n)
        {
            return false;
        }
        string res = "";

        while(data[i] != ',')
        {
            res = res + data[i];
            // printf("i = %d n = %d %c \n", i,n, data[i]);
            // printf("i = %d n = %d \n", i,n);
            i++;
        }
        if(res == "n")
        {
            ++i;
            return false;
        }
        // cout<<res<<endl;
        rint = stoi(res);
        i++;
        return true;
    }
    void DFS(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        cout<<root->val<<", ";
        DFS(root->left);
        DFS(root->right); 
    }
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        int n = data.size();
        int i = 0;
        if(n==0) return nullptr;
        int val;
        bool success;
        success = parse(data, i, n, val);
        TreeNode* root = new TreeNode(val);
        queue<TreeNode*> Q;
        Q.push(root);
        // int cnt=0;
        while(i+1<n)
        {
            // printf(" %d ", i);
            cout<<endl;
            TreeNode* temp = Q.front();
            success = parse(data, i, n, val);
            if(success)
            {
                temp->left = new TreeNode(val);
                printf(" %d ->left = %d ", temp->val, temp->left->val);
            }
            if(nullptr == temp)
            {
                Q.push(nullptr);
            }
            else
            {
                Q.push(temp->left);
            }
            cout<<endl;
            success = parse(data, i, n, val);
            if(success)
            {
                temp->right = new TreeNode(val);
                printf(" %d ->right = %d ", temp->val, temp->right->val);
            }
            if(nullptr == temp)
            {
                Q.push(nullptr);
            }
            else
            {
                Q.push(temp->right);
            }
            Q.pop();
            cout<<endl<<temp<<" Print: ";
            DFS(temp);
        }
        cout<<endl<<"Print: ";
        DFS(root);
        return root;
    }
};
