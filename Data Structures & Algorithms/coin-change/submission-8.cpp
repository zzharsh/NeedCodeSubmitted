class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        sort(coins.begin(), coins.end());
        if(amount<coins[0]) return -1;
        int i = 0;
        vector<int> DP(amount+1, -1);
        DP[0] = 0;
        bool flag = 0;
        int j = 0;
        int cnt = 0;
        while(i <= amount)
        {
            if(j < coins.size() && i == coins[j])
            {
                DP[i] = 1;
                cout<<i<<" "<<DP[i]<<" | ";
                j++;
            }
            else if (j< coins.size() && i < coins[j])
            {
                if(j!=0)
                {
                   int min_cnt = INT_MAX;
                   for(int k = j-1; k>=0;--k)
                   {
                        if(DP[i - coins[k]]!=-1)
                        {
                           min_cnt = min(min_cnt, DP[i - coins[k]]);
                           DP[i] = min_cnt + 1;
                        }
                   }
                   cout<<i<<" "<<DP[i]<<" | ";
                }
            }
            else
            {
                int min_cnt = INT_MAX;
                for(int k = coins.size()-1; k>=0;--k)
                {
                    if(DP[i - coins[k]]!=-1)
                    {
                        min_cnt = min(min_cnt, DP[i - coins[k]]);
                        DP[i] = min_cnt + 1;        
                    }
                }
                cout<<i<<" "<<DP[i]<<" | ";
            }
            i++;
        }
        return DP[amount];
    }
};
