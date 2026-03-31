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
    int DFS(int it, int curr)
    {
        // ans = max(ans, curr);
        pos lP = toPos(it);
        int i = lP.i;
        int j = lP.j;
        cout<<i<<" "<<j<<" "<<curr<<"\n";
        if (i>=m || i < 0) return 0;
        if (j>=n || j < 0) return 0;
        if(visited.find(it) == visited.end()) return 0;
        if(G[i][j] == 1)
        {
            // curr++;
            visited.erase(it);
            int c = 1;
            c += DFS(toIt({i+1, j}), curr+1);
            c += DFS(toIt({i-1, j}), curr+1);
            c += DFS(toIt({i, j+1}), curr+1);
            c += DFS(toIt({i, j-1}), curr+1);
            return c;
        }
        else
        {
            return 0;
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        G = move(grid);
        m = G.size();
        n = G[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(G[i][j] == 1)
                {
                    int it = toIt(pos(i, j));
                    // cout<<it<<" "<<i<<" "<<j<<"\n";
                    visited.insert(it);
                }
            }
        }
        while(!visited.empty())
        {
            cout<<"starting \n";
            ans = max(ans, DFS(*visited.begin(), 0));
        }
        // pos a = toPos(10);
        // cout<< m<<" "<<n<<" "<<a.i<<" "<<a.j;
        return ans;
    }
};
