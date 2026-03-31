class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> visited(n+1,0);
        for(int i =0; i < n; ++i)
        {
            // cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<visited[edges[i][0]]<<" "<<
            // visited[edges[i][1]]<<"\n";
            if(visited[edges[i][0]] > 0 && visited[edges[i][1]] > 0)
            {
                return edges[i];
            }
            visited[edges[i][0]]++;
            visited[edges[i][1]]++;
        }
        return {};
    }
};
