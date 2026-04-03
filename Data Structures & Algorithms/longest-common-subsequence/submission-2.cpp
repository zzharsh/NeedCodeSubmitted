class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int res = 0;
        // string text3 = text2;
        // text2 = text1;
        // text1 = text3;
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> DP(m+1, vector<int>(n+1,0));
        for(int i = m-1; i > -1; --i)
        {
            for(int j = n-1; j > -1; --j)
            {
                if(text1[i] == text2[j])
                {
                    DP[i][j] = DP[i+1][j+1] + 1;
                }
                else
                {
                    DP[i][j] = max(DP[i+1][j], DP[i][j+1]);
                }
            }
        }
        // printf("| 0 |");
        // for(int i = 0; i < m; ++i)
        // {
        //     printf("| %c |", text1[i]);
        //     // for(int j = 0; j < n; ++j)
        //     // {
        //     //     printf(text1[i], text2[j])
        //     // }
        // }
        // cout<<endl;
        // vector<bool> flags(n);
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                // if(!flags[j])
                // {
                //     printf("| %c |", text2[j]);
                //     flags[j] = true;
                // }
                printf("| %d |", DP[i][j]);
            }
            cout<<endl;
        }
        return DP[0][0];
    }
};
