class Solution {
public:
vector<vector<int>> H;
    int m, n;
    int k = 0;
    void Fill(int i,
              int j, 
              vector<vector<int>>& waters, 
              vector<vector<bool>>& visited)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
        {
            return;
        }
        if(visited[i][j])
        {
            return;
        }
        visited[i][j] = true;
        waters[i][j] = true;
        if(i-1 >= 0 && H[i-1][j] >= H[i][j])
        {
            Fill(i-1, j, waters, visited);
        }
        if(i+1 < m && H[i+1][j] >= H[i][j])
        {
            Fill(i+1, j, waters, visited);
        }
        if(j-1 >= 0 && H[i][j+1] >= H[i][j])
        {
            Fill(i, j-1, waters, visited);
        }
        if(j+1 < n && H[i][j+1] >= H[i][j])
        {
            Fill(i, j+1, waters, visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        H = move(heights);
        vector<vector<int>> ans;
        vector<vector<int>> pacific(m, vector<int>(n, false)),
                            atlantic(m, vector<int>(n, false));
        vector<vector<bool>> v1(m, vector<bool>(n,false));
        vector<vector<bool>> v2(m, vector<bool>(n,false));
        for(int i = 0; i < m; ++i)
        {
            pacific[i][0]    = true;
            atlantic[i][n-1] = true;
        }
        for(int j = 0; j < n; ++j)
        {
            pacific[0][j]    = true;
            atlantic[m-1][j] = true;
        }
        for(int i = 0; i < m; ++i)
        {
            Fill(i, 0, pacific, v1);
            Fill(i, n-1, atlantic, v2);
        }
        for(int j = 0; j < n; ++j)
        {
            Fill(0, j, pacific, v1);
            Fill(m-1, j, atlantic, v2);
        }
        heights = move(H);
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(atlantic[i][j] && pacific[i][j])
                {
                    ans.push_back({i,j});
                }
                printf("{%d,%u,%u} ",heights[i][j], atlantic[i][j], pacific[i][j]);
            }
            cout<<endl;
        }
        return ans;
        
    }
};
