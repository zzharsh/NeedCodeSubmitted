class Solution {
public:
    vector<vector<int>> G;
    int m, n;
    struct index{int i, j; index(int a, int b): i(a), j(b){}};
    bool minDis(int ii, int jj, int dis)
    {
        if(ii < m && ii >=0 && jj < n && jj >=0 && G[ii][jj] != -1 && G[ii][jj] !=0)
        {
            if(G[ii][jj] != 0 && G[ii][jj] != -1)
            {
                G[ii][jj] = min(dis, G[ii][jj]);
            }
            return true;
        }
        return false;
    }
    void visit(int i, int j)
    {
        queue<index> Q;
        Q.push({i,j});
        unordered_set<int> visited;
        int dis = 0;
        while(!Q.empty())
        {
            int ii = Q.front().i;
            int jj = Q.front().j;
            if(visited.find(ii*n+jj) == visited.end())
            {
                dis = G[ii][jj] + 1;
                // cout<<ii<<" "<<jj<<" "<<dis<<"\n";
                if(minDis(ii+1, jj, dis)) Q.push({ii+1, jj});
                if(minDis(ii-1, jj, dis)) Q.push({ii-1, jj});
                if(minDis(ii, jj+1, dis)) Q.push({ii, jj+1});
                if(minDis(ii, jj-1, dis)) Q.push({ii, jj-1});
                visited.insert(ii*n+jj);
            }
            Q.pop();
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        G = move(grid);
        m = G.size();
        n = G[0].size();
        for(int i = 0; i< m; ++i)
        {
            for(int j = 0; j< n; ++j)
            {
                if(G[i][j] == 0) visit(i,j);
            }
        }
        grid = move(G);
    }
};
