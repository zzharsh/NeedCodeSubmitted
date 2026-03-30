class Solution {
public:
    vector<int> parents;
    int ffind(int x)
    {
        while(parents[x] != x)
        {
            x = parents[x];
        }
        return x;
    }
    bool uunion(int x, int y)
    {
        int pX = ffind(x);
        int pY = ffind(y);
        if(pX == pY) return true;
        if(pX < pY)
        {
            parents[y] = pX;
            parents[pY] = pX;
        }
        else
        {
            parents[x] = pY;
            parents[pX] = pY;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        parents = move(vector<int>(n+1, 0));
        for(int i = 0; i < n; ++i)
        {
            parents[i+1] = i+1;
        }
        for(int i = 0; i < edges.size(); ++i)
        {
            if(uunion(edges[i][0], edges[i][1])) return false;
        }
        return true;

    }
};
