class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
        {
            return 1;
        }
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> DP(amount + 1, vector<int>(n, 0));
        for(int i = 0; i < amount+1; ++i)
        {
            for(int j = n-1; j > -1; --j)
            {
                if(i < coins[j])
                {
                    DP[i][j] = 0;
                }   
                else if( i == coins[j])
                {
                    DP[i][j] = 1;
                }
                else
                {
                    if(j+1 < n)
                    {
                        DP[i][j] = DP[i - coins[j]][j] + DP[i][j+1];
                    }
                    else
                    {
                        DP[i][j] = DP[i - coins[j]][j];
                        //  + DP[i][j+1];
                    }
                }
            }
        }
        // for(int i = 0; i < amount+1; ++i)
        // {
        //     for(int j = 0; j < n; ++j)
        //     {
        //         printf("%d ", DP[i][j]);

        //     }
        //     cout<<endl;
        // }
        return DP[amount][0];
    }
};
