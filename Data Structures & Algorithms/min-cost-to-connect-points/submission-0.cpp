class Solution {
public:
    int cost(vector<int>& p1, vector<int>& p2)
    {
        return (abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // find the cost per edge:
        int n = points.size();
        vector<multimap<int, int>> adjMatrix(n);
        for(int i = 0 ; i < n; ++i)
        {
            cout<<i<<" : ";
            for(int j = 0; j < n; ++j)
            {
                if(i==j)
                {
                    continue;
                }
                cout<<j<<" - ";
                cout<<cost(points[i], points[j])<<" , ";
                adjMatrix[i].insert(make_pair(cost(points[i], points[j]), j));
            }
            cout<<endl;
        }
        for(int i = 0; i < n; ++i)
        {
            cout<<i<<" - ";
            for(auto x:adjMatrix[i])
            {
                cout<<x.second<<": "<<x.first<<" | ";
            }
            cout<<endl;
        }

        // Prim's algorithm:
        multimap<int, int> nextLowest;
        int ans = 0;
        vector<bool> visited(n, false);
        int numVisited = 0;
        nextLowest.insert(make_pair(0,0));
        while(numVisited != n)
        {
            int cost = nextLowest.begin()->first;
            int node = nextLowest.begin()->second;
            auto it = nextLowest.begin();
            nextLowest.erase(it);
            if(!visited[node])
            {
                visited[node] = true;
                cout<<"selected "<<node<<" : "<<cost<<"\n";
                ans += cost;
                numVisited++;
                for(auto x:adjMatrix[node])
                {
                    int scost = x.first;
                    int snode = x.second;
                    if(!visited[snode])
                    {
                        nextLowest.insert(make_pair(scost, snode));
                    }
                }
            } 
        }
        return ans;
    }
};
