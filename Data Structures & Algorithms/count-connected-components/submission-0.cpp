class Solution {
public:
    vector<bool> visited, currentPath;
    vector<vector<int>> adjList; 
    void dfs(int node)
    {
        if(currentPath[node])
        {
            return;
        }
        currentPath[node] = true;
        for(int i = 0; i < adjList[node].size(); ++i)
        {
            dfs(adjList[node][i]);
        }
        visited[node] = true;
        currentPath[node] = false;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        visited     = move(vector<bool>(n,false));
        adjList     = move(vector<vector<int>>(n, vector<int>()));
        int ans     = 0;
        for(int i = 0; i < edges.size(); ++i)
        {
            adjList[edges[i][1]].push_back(edges[i][0]);
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i = 0; i < n; ++i)
        {
            // cout<<i<<" : ";
            // for(int j = 0; j < adjList[i].size(); ++j)
            // {
            //     cout<<adjList[i][j]<<" ";
            // }
            // cout<<"\n";

            if(!visited[i])
            {
                currentPath = move(vector<bool>(n, false)); 
                dfs(i);
                ans++;
            }
        }
        return ans;

        

    }
};
