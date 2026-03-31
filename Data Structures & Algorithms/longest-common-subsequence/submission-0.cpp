class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
     int m = text1.size(), n = text2.size(), i=0,j=0;
     vector<vector<int>> DP(m, vector<int>(n,0));
     for(i=m-1;i>=0;--i)
     {
        for(j=n-1;j>=0;--j)
        {
            int s = text1[i] == text2[j];
            if((i==m-1) && (j==m-1))
            {
                DP[i][j] = s;
            }

            else if(i==m-1)
            {
                DP[i][j] = DP[i][j+1] + s;
            }
            else if(j==n-1)
            {
                DP[i][j] = DP[i+1][j] + s;
            }
            else
            {
                DP[i][j] = max(DP[i][j+1], DP[i+1][j]) + s;
            }
        }
     }
     return DP[0][0];
    }
};
