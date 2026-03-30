class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int n = prices.size();
        int ans = 0;
        vector<int> DP(n,0);
        // cout<<0<<" ";
        for(int i = n-2;i>=0;--i)
        {
            
            DP[i] = max(DP[i], DP[i+1]);
            for(int j=i+1;j<n;++j)
            {
                cout<<i<<" "<<j<<" ";
                if(j+2 < n)
                {
                    DP[i] = max(DP[i], max(prices[j] - prices[i], 0) + DP[j+2]);
                }
                else
                {
                    DP[i] = max(DP[i], prices[j] - prices[i]);
                    // cout<<" YES "<<prices[i] - prices[j]<<" ";
                }
            }
            cout<<DP[i]<<"\n";
        }
        return DP[0];
    }
};
