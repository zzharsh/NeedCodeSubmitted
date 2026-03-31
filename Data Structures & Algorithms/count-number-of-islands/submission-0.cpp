class Solution {
public:
    void DFS(int t)
    {
        if (cnt++ > 20) return;
        int i = t/n, j = t%n;
        if(i >= m || j >= n) return;
        if(G[i][j] == '0') return;
        cout<<"Erase: "<<t<<"\n";
        unvisited.erase(t);
        G[i][j] = '0';
        if(i-1 >=0 && G[i-1][j] == '1')
        {
            DFS((i-1)*n+j);
        }
        if(i+1 < m && G[i+1][j] == '1')
        {
            DFS((i+1)*n+j);
        }
        if(j+1 < n && G[i][j+1] == '1')
        {
            DFS((i)*n+j+1);
        }
        if(j-1 >= 0 && G[i][j-1] == '1')
        {
            DFS((i)*n+j-1);
        }
    }
    int m, n, ans = 0;
    int cnt = 0;
    unordered_set<int> unvisited;
    vector<vector<char>> G;
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i< m; ++i)
        {
            for (int j = 0; j<n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    unvisited.insert(i*n+j);
                    cout<<"insert "<<i*n+j<<"\n";
                }
            }
        }
        G = std::move(grid);
        while(!unvisited.empty())
        {
            int k = *(unvisited.begin());
            DFS(k);
            ans++;
            break;
        }
        return ans;
    }
};
