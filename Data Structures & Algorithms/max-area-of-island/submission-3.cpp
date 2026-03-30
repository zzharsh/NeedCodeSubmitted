class Solution {
public:
    int m, n;
    vector<vector<int>> G;
    int DFS(int i, int j)
    {
        if(i<0 || i>= m || j<0 || j>=n || G[i][j]==0) return 0;
        int c = 1;
        G[i][j] = 0;
        c += DFS(i+1, j);
        c += DFS(i-1, j);
        c += DFS(i, j+1);
        c += DFS(i, j-1);
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        G = move(grid);
        m = G.size();
        n = G[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(G[i][j] == 1)
                {
                    ans = max(ans, DFS(i,j));
                }
            }
        }
        return ans;
    }
};
