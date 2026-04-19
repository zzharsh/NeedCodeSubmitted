class Solution {
public:
    int source, dest, mostK, res = -1;
    vector<vector<int>> FinalCost;
    vector<vector<pair<int, int>>> adjList;
    void DFSIterate(int i, int cost, int k)
    {
        printf("called = %d %d %d %d %d\n", i, k, cost, FinalCost[i][0], FinalCost[i][1]);
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
        if (FinalCost[i][0] <= cost && FinalCost[i][1] <= k)
        {
            return;
        }
        FinalCost[i] = {cost, k};
        for (int j = 0; j < adjList[i].size(); ++j)
        {
            DFSIterate(adjList[i][j].first, FinalCost[i][0] + adjList[i][j].second, FinalCost[i][1] + 1);
        }

    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        FinalCost = std::move(vector<vector<int>>(n, vector<int>(2, INT_MAX)));
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
