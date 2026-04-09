class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m==0)
        {
            return n;
        }
        if(n==0)
        {
            return m;
        }
        vector<vector<int>> DP(n+1, vector<int>(m+1, 200));
        for(int j = m-1; j >= 0; --j)
        {
            if(word1[j] == word2[n-1])
            {
                DP[n-1][j] = m - j - 1;
            }
            else
            {
                DP[n-1][j] = min(DP[n-1][j+1] + 1 , m - j);
                
            }
            printf("DP[%d][%d] = %d ", n-1, j, DP[n-1][j]);
            // cout<<j<<" "<<DP[n-1][j]<<endl;
        }
        for(int i = n-2; i >= 0; --i)
        {
            if(word1[m-1] == word2[i])
            {
                DP[i][m-1] = n - i - 1;
            }
            else
            {
                DP[i][m-1] = min(DP[i+1][m-1] + 1 , n - i);
                
            }
        }
        for(int i = n-2; i >= 0; i--)
        {
            cout<<endl;
            for (int j = m-2; j >= 0; --j)
            {
                if(word1[j] == word2[i])
                {
                    DP[i][j] = DP[i+1][j+1];
                }
                else
                {
                    int t = DP[i][j+1];
                    cout<<t<<" ";
                    t = min(DP[i+1][j], t);
                    cout<<t<<" ";
                    t = min(DP[i+1][j+1], t);
                    cout<<t<<" ";
                    DP[i][j] = t + 1;
                }
                printf("DP[%d][%d] = %d ",i, j, DP[i][j]);

            }
        }
        return DP[0][0];

    }
};
