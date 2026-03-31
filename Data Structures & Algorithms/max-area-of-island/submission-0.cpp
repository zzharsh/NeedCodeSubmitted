class Solution {
public:
    int m = 0, n = 0, ans = 0;
    vector<vector<int>> G;
    struct pos{
        int i, j;
        pos(int a, int b): i(a), j(b){}
        pos(){}
    };
    unordered_set<int> visited;
    pos toPos(int it)
    {
        pos lP;
        lP.i = it / n;
        lP.j = it % n;
        return lP;
    }
    int toIt(pos lP)
    {
        return lP.i * n + lP.j;
    }
    void DFS(int it, int curr)
    {
        pos lP = toPos(it);
        int i = lP.i;
        int j = lP.j;

        if (i>=m) return;
        if (j>=n) return;
        if(visited.find(it) == visited.end()) return;
        if(G[i][j] == 1)
        {
            curr++;
            ans = max(ans, curr);
            visited.erase(it);
            DFS(toIt({i+1, j}), curr);
            DFS(toIt({i-1, j}), curr);
            DFS(toIt({i, j+1}), curr);
            DFS(toIt({i, j-1}), curr);

        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        G = move(grid);
        m = G.size();
        n = G.size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(G[i][j] == 1)
                {
                    visited.insert(toIt(pos(i, j)));
                }
            }
        }
        while(!visited.empty())
        {
            DFS(*visited.begin(), 0);
        }
        // pos a = toPos(10);
        // cout<< m<<" "<<n<<" "<<a.i<<" "<<a.j;
        return ans;
    }
};
