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
            cout<<j<<" "<<DP[n-1][j]<<endl;
        }
        for(int i = n-2; i >= 0; i--)
        {
            for (int j = m-1; j >= 0; --j)
            {
                if(word1[j] == word2[i])
                {
                    DP[i][j] = DP[i+1][j+1];
                }
                else
                {
                    int t = DP[i][j+1];
                    t = min(DP[i+1][j], t);
                    t = min(DP[i+1][j+1], t);
                    DP[i][j] = t + 1;
                }
            }
        }
        return DP[0][0];

    }
};
