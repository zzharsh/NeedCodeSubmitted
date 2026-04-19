class Solution {
public:
    int source, dest, mostK, res = -1;
    vector<int> FinalCost;
    vector<vector<pair<int, int>>> adjList;
    void DFSIterate(int i, int cost, int k)
    {
        printf("called = %d %d %d %d\n", i, k, cost, FinalCost[i]);
        if(i == source && k > 0)
        {
            return;
        }
        if(i == dest)
        {
            if(k <= mostK+1)
            {
                if(res == -1)
                {
                    res = cost;
                }
                else
                {
                    res = min(res, cost);
                }
            }
            return;
        }
        if(k > mostK + 1)
        {
            return;
        }
        if (FinalCost[i] <= cost)
        {
            return;
        }
        FinalCost[i] = cost;
        for (int j = 0; j < adjList[i].size(); ++j)
        {
            DFSIterate(adjList[i][j].first, FinalCost[i] + adjList[i][j].second, k+1);
        }

    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        FinalCost = std::move(vector<int>(n, INT_MAX));
        adjList = std::move(vector<vector<pair<int, int>>>(n));
        source = src;
        dest = dst;
        mostK = k;
        for(int i = 0; i < flights.size(); ++i)
        {
            int s = flights[i][0];
            int e = flights[i][1];
            int c = flights[i][2];
            adjList[s].push_back(make_pair(e, c));
        }
        res = -1;
        // FinalCost[src] = 0;
        DFSIterate(src, 0, 0);
        return res;
    }
};
