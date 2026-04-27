class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // if(p[n-1] == '*')
        // {
        //     return true;
        // }
        vector<vector<bool>> DP(n+1, 
            vector<bool>(m+1, false));
        
        DP[0][0] = true;
        char ch = '.';
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(p[i] == s[j])
                {
                    // ch = s[i];
                    DP[i+1][j+1] = DP[i][j];
                    // cout<<" yes then why? "<<DP[i+1][j+1]<<i<<j<<DP[i][j]<<endl;

                }
                else if(p[i] == '.')
                {
                    // ch = s[i];
                    DP[i+1][j+1] = DP[i][j];
                }
                else if(p[i] == '*')
                {
                    DP[i+1][j] = DP[i+1][j] || DP[i-1][j];
                    DP[i+1][j+1] = DP[i+1][j+1] || DP[i-1][j+1];
                    if(p[i-1] == '.')
                    {
                        DP[i+1][j+1] = DP[i+1][j+1] || DP[i][j] || DP[i+1][j];
                    }
                    else
                    {
                        DP[i+1][j+1] = DP[i+1][j+1] || (
                            (p[i-1] == s[j]) &&
                            (DP[i][j] || DP[i+1][j])) ;
                    }
                }
                printf("DP[%d][%d] = %d (%c, %c)\n", i+1, j+1, static_cast<int>(DP[i+1][j+1]) , p[i], s[j]);
            }
        }
        return DP[n][m];
    }
};
