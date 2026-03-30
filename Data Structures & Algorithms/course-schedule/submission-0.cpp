class Solution {
public:
    vector<bool> visited;
    unordered_set<int> currTree;
    vector<vector<int>> adjList;
    int n;
    bool cycle(int node)
    {
        if(currTree.find(node) != currTree.end())
        {
            return true;
        }
        if(visited[node] == true)
        {
            return false;
        }
        currTree.insert(node);
        for(int i:adjList[node])
        {
            if (cycle(i) == true)
            {
                return true;
            }
        }
        visited[node] = true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        visited = move(vector<bool>(n,false));
        adjList.resize(n);
        for(vector<int> adj:prerequisites)
        {
            adjList[adj[1]].push_back(adj[0]);
        }
        for(int i = 0; i < n; ++i)
        {
            if(visited[i] == false)
            {
                currTree.clear();
                if(cycle(i) == true) 
                {
                    return false;
                }
            }
        }
        return true;
    }
};
