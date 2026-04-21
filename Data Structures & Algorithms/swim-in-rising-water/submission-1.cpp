class Solution {
public:
    int offset = 0;
    int res = 0;
    int n;
    vector<vector<int>> G;
    multimap<int, pair<int, int>> Edges;
    void DFS()
    {
        if(Edges.empty())
        {
            return;
        }
        // int i, j;
        int cnt = 0;
        while(true && cnt<100)
        {
            auto it = Edges.begin();
            res = max(it->first, res);
            int i = it->second.first, j = it->second.second;
            printf("(%d, %d): %d, %d\n", i, j, it->first, res);
            if(i == n-1 && j == n-1)
            {
                return;
            }
            Edges.erase(it);
            G[i][j] = -1;
            if(i+1 < n && G[i+1][j] >= 0)
            {
                Edges.insert(make_pair(
                    max(G[i+1][j] - offset, 0), make_pair(i+1, j)));
                    G[i+1][j] = -1;
            }
            if(i-1 > -1 && G[i-1][j] >= 0)
            {
                Edges.insert(make_pair(
                    max(G[i-1][j] - offset, 0), make_pair(i-1, j)));
                    G[i-1][j] = -1;
            }
            if(j+1 < n && G[i][j+1] >= 0)
            {
                Edges.insert(make_pair(
                    max(G[i][j+1] - offset, 0), make_pair(i, j+1)));
                    G[i][j+1] = -1;
            }
            if(j-1 > -1 && G[i][j-1] >= 0)
            {
                Edges.insert(make_pair(
                    max(G[i][j-1] - offset, 0), make_pair(i, j-1)));
                    G[i][j-1] = -1;
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        if(n == 1)
        {
            return grid[0][0];
        }
        offset = 0;
        res = grid[0][0]; 
        grid[0][0] = -1;
        Edges = std::move(multimap<int, pair<int, int>>());
        Edges.insert(make_pair(
            max(grid[0][1] - offset, 0), make_pair(0, 1)));
            grid[0][1] = -1;
        Edges.insert(make_pair(
            max(grid[1][0] - offset, 0), make_pair(1, 0)));
            grid[1][0] = -1;
        G = std::move(grid);
        DFS();
        grid = std::move(G);
        return res;
    }
};
