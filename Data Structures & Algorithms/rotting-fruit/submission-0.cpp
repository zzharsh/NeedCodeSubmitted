class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    int bfs(int i, int j)
    {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] <= 0)
        {
            return 1000;
        }
        if(grid[i][j] > 1)
        {
            return grid[i][j];
        }
        grid[i][j] = -1;
        int mn = 1000;
        mn = min(bfs(i+1, j), mn);
        mn = min(bfs(i-1, j), mn);
        mn = min(bfs(i, j+1), mn);
        mn = min(bfs(i, j-1), mn);
        grid[i][j] = mn + 1;
        cout<<i<<" "<<j<<" "<<grid[i][j]<<"\n";
        return grid[i][j];
    }
    int orangesRotting(vector<vector<int>>& G) {
        grid = move(G);
        int i, j;
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> Q1, Q2;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    bfs(i, j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                res = max(res, grid[i][j]);
            }
        }
        if(res >= 1000)
        {
            return -1;
        }
        else
        {
            return res - 2;
        }
    }
};
