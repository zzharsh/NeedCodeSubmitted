class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m, vector<int>(n,1));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j< n; ++j)
            {
                if((i==0) && (j==0))
                {
                    continue;
                }
                else if(i==0)
                {
                    DP[i][j]  = DP[i][j-1];
                }
                else if(j==0)
                {
                    DP[i][j] = DP[i-1][j];
                }
                else
                {
                    DP[i][j] = DP[i-1][j] + DP[i][j-1];
                }
            }
        }
        return DP[m-1][n-1];

    }
};
