class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> DP(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i)
        {
            for(int j = i; j < m; ++j)
            {
                if(i == 0 && j == 0)
                {
                    DP[i][j] = ((s[j] == p[i]) || p[i] == '.'|| p[i] == '*');
                }
                if( i - 1 < 0)
                {
                    if(p[i] == '*')
                    {
                        DP[i][j] = true;
                    }
                }
                else
                {
                    if(p[i] == '*')
                    {
                        DP[i][j] = DP[i-1][j-1] || DP[i][j-1];
                    }
                    else
                    {
                        DP[i][j] = DP[i-1][j-1] && (
                            s[j] == p[i] ||
                            p[i] == '.'
                        );
                    }
                }
                printf("DP[%d][%d] = %d (%c, %c)\n", i, j, static_cast<int>(DP[i][j]) , p[i], s[j]);
            }
        }
        return DP[n-1][m-1];
    }
};
