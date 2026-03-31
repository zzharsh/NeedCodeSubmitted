class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        if (m <= 2 && n <= 2)
        {
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    ans.push_back({i , j});
                }
            }
            return ans;
        }
        vector<vector<bool>> pacific(m, vector<bool>(n, 0)),
                             atlantic(m, vector<bool>(n, 0));
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
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if((heights[i][j] >= heights[i][j-1]) && pacific[i][j-1])
                {
                    pacific[i][j] = true;
                }
                if((heights[i][j] >= heights[i-1][j]) && pacific[i-1][j])
                {
                    pacific[i][j] = true;
                }
            }
        }
        for(int i = m-2; i >= 0; --i)
        {
            for(int j = n-2; j >= 0; --j)
            {
                if((heights[i][j] >= heights[i+1][j]) && atlantic[i+1][j])
                {
                    atlantic[i][j] = true;
                }
                if((heights[i][j] >= heights[i][j+1]) && atlantic[i][j+1])
                {
                    atlantic[i][j] = true;
                }
            }
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(atlantic[i][j] && pacific[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
