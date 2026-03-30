class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int a = 0;
        for(int i = 0; i <= n ; ++i)
        {
            a = 0;
            int k = 1;
            for (int j = 0; j <=10;++j)
            {
                if (k & i)
                {
                    cout<<k<<" / "<<i<<" ";
                    a++;
                }
                k *=2;
            }
            cout<<"\n";
            ans.push_back(a);
        }
        return ans;
        
    }
};
