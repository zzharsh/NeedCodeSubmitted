class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i0 = -1, j0 = -1;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    if(i !=0 && j != 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                    else if(i==0)
                    {
                        i0 = 0;
                    }
                    else
                    {
                        j0 = 0;
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        for(int i = 1; i < m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 0; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        // int i0 = matrix[0][0];
        // int j0 = 
        for(int i = 1; i < m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 0; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
        for(int j = 0; j < n; ++j)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 0; i < m; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(i0 == 0)
        {
            for(int j = 0; j < n; ++j)
            {
                matrix[0][j] = 0;
            }
        }
        if(j0 == 0)
        {
            for(int i = 0; i < m; ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
