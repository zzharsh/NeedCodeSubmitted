class Solution {
public:
    vector<vector<int>> DP, mat;
    int res = 0;
    int m, n;
    int DFS(int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
        {
            return 0;
        }
        if(DP[i][j] > 0)
        {
            return DP[i][j];
        }
        int mx = 0;
        if((i+1 < m) && mat[i+1][j] > mat[i][j])
        {
            mx = max(DFS(i+1, j), mx);
        }
        if((i-1 >= 0) && mat[i-1][j] > mat[i][j])
        {
            mx = max(DFS(i-1, j), mx);
        }
        if((j+1 < n) && mat[i][j+1] > mat[i][j])
        {
            mx = max(DFS(i, j+1), mx);
        }
        if((j-1 >= 0) && mat[i][j-1] > mat[i][j])
        {
            mx = max(DFS(i, j-1), mx);
        }
        DP[i][j] = mx + 1;
        res = max(res, DP[i][j]);
        return DP[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        DP = vector<vector<int>>(m, vector<int>(n,0));
        mat = move(matrix);
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(DP[i][j] == 0)
                {
                    DFS(i, j);
                }
            }
        }
        return res;
        
    }
};
