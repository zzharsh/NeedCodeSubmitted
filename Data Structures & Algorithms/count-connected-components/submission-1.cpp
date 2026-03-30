class Solution {
public:
    vector<int> parents;
    int find(int x)
    {
        while(x != parents[x])
        {
            x = parents[x];
        }
        return x;
    }
    void unionn(int x, int y)
    {
        int parX = find(x);
        int parY = find(y);
        if(parX == parY)
        {
            return;
        }
        if(parX < parY)
        {
            parents[y] = parX;
            parents[parY] = parX;
        }
        else
        {
            parents[x] = parY;
            parents[parX] = parY;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parents = move(vector<int>(n+1));
        for(int i = 0; i < n; ++i)
        {
            parents[i+1] = i+1;
            // cout<<parents[i+1]<<" "<<i+1<<"\n";
        }
        // return 0;
        for(auto edge:edges)
        {
            unionn(edge[0], edge[1]);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(parents[i+1] == i+1)
            {
                ans++;
            }
        }
        return ans;
    }
};
