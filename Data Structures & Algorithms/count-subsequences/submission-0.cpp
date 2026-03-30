class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size(), m = s.size();
        vector<vector<int>> DP(n+1, vector<int>(m+1,0));
        for(int i = n-1; i >= 0; --i)
        {
            for(int j = m-1; j >= 0; --j)
            {
                bool eq = t[i] == s[j];
                if(eq)
                {
                    DP[i][j] = DP[i+1][j+1] + DP[i][j+1];
                }
                else
                {
                    DP[i][j] = DP[i][j+1];
                }
                if(i == n-1)
                {
                    DP[i][j]+=eq;
                }
                cout<<DP[i][j]<<" ";
            }
            cout<<endl;
        }
        return DP[0][0];
    }
};
