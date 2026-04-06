class Solution {
public:
    int hash(int i, int j)
    {
        return i * n + j;
    }
    vector<int> dehash(int h)
    {
        return {h / n, h % n};
    }
    void Q2Push(int i, int j, queue<int>& Q2)
    {
        // printf("i, j= %d, %d \n", i, j);
        // return;   
        if((i < 0) || (i >= m) || (j < 0) || (j >= n))
        {
            return;
        }
        // printf("Checking: G[%d][%d] = %d \n", i, j, G[i][j]);
        if(G[i][j] == 1)
        {
            printf("Rotting: %d, %d \n", i, j);
            Q2.push(hash(i, j));
        }
    }
    int m, n;
    vector<vector<int>> G;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> Q1, Q2;
        int res = 0;
        m = grid.size();
        n = grid[0].size();
        int freshCnt = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                printf(" Hash %d, Dehash: %d, %d\n", hash(i,j), dehash(hash(i,j))[0], dehash(hash(i,j))[1]);
                if(grid[i][j] == 1)
                {
                    freshCnt++;
                }
                if(grid[i][j] == 2)
                {
                    Q1.push(hash(i, j));
                }
            }
        }
        G = move(grid);
        // cout<<Q1.size()<<" "<<Q1.empty()<<" "<<(!Q1.empty())<<"\n";
        if(0==freshCnt) return 0;
        if(Q1.empty()) return -1;
        while(!Q1.empty())
        {
            // res++;
            // cout<<Q1.size()<<" "<<Q1.empty()<<" "<<(!Q1.empty())<<"\n";
            while(!Q1.empty())
            {
                // cout<<Q1.size()<<" "<<Q1.empty()<<" "<<(!Q1.empty())<<"\n";
                vector<int> front = dehash(Q1.front());
                Q1.pop();
                int i = front[0], j = front[1];
                cout<<i<<j<<endl;
                if(G[i][j] == 3)
                {
                    continue;
                }
                // Q2Push(i-1, j, Q2);
                // Q2Push(i+1, j, Q2);
                // Q2Push(i, j-1, Q2);
                // Q2Push(i, j+1, Q2);
                // G[i][j] = 3;
                // cout<<Q2.size()<<" "<<Q2.empty()<<" "<<(!Q2.empty())<<"\n";
            }
            while(!Q2.empty())
            {
                int h = Q2.front();
                Q1.push(h);
                Q2.pop();
            }
            res++;
            // cout<<Q1.size()<<" "<<Q1.empty()<<" "<<(!Q1.empty())<<"\n";
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                printf("G[%d][%d]: %d ", i, j, G[i][j]);
                if(G[i][j] == 1)
                {
                    return -1;
                }
            }
            cout<<" "<<res<<" \n";
        }
        return res-1;
    }
};
