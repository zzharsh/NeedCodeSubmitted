class Solution {
public:
    bool cycle = false;
    vector<bool> visited;
    vector<vector<int>> adjList;
    vector<int> res;
    int n;
    void DFS(int i, unordered_set<int> currPath)
    {
        cout<<i<<" "<<visited[i]<<" "<<cycle<<" "<<" \n";
        if(visited[i] == true)
        {
            cout<<" visited "<<endl;
            return;
        }
        if(cycle)
        {
            cout<<" Cycle "<<endl;
            return;
        }
        if(currPath.find(i) != currPath.end())
        {
            cout<<" cycle "<<endl;
            cycle = true;
            cout<<endl;
            return;
        }
        // cout<<visited[i]<<" "<<cy/cle<<" "<<" \n";
        cout<<endl;
        currPath.insert(i);
        for(int j = 0; j < adjList[i].size(); ++j)
        {
            cout<<" clalling "<<adjList[i][j]<<endl;
            DFS(adjList[i][j], currPath);
        }
        currPath.erase(i);
        visited[i] = true;
        res.push_back(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        adjList = vector<vector<int>>(n);
        visited = vector<bool>(n, false);
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < n; ++i)
        {
            cout<<i<<" ";
            for(int j = 0; j < adjList[i].size(); ++j)
            {
                cout<<adjList[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                cout<<" Calling "<<i<<endl;
                DFS(i, unordered_set<int>());
            }
            if(true == cycle)
            {
                return {};
            }
        }
        if(cycle == true)
        {
            return {};
        }
        return res;
    }
};
