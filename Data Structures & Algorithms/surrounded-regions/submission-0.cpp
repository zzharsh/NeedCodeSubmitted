class Solution {
public:
    vector<vector<int>> visited;
    vector<vector<char>> B;
    vector<vector<bool>> otw;
    int m, n;
    bool traverseO(int i, int j)
    {
        
        if( i < 0 || i >= m || j < 0 || j >= n) 
        {
            return true;
        }
        if(visited[i][j] != 0)
        {
            return visited[i][j] > 0 ? true : false;
        }
        if('X' == B[i][j])
        {
            visited[i][j] = -1;
            return false;
        }
        if(otw[i][j])
        {
            return false;
        }
        otw[i][j] = true;
        cout<<"visited "<<i<<" "<<j<<" "<<B[i][j]<<" "<<B.size()<<" "<<B[0].size()<<"\n";
        bool flag = false;
        flag = flag || traverseO(i, j+1);
        flag = flag || traverseO(i+1, j);
        flag = flag || traverseO(i-1, j);
        flag = flag || traverseO(i, j-1);
        visited[i][j] = flag ? 1 : -1;
        // cout<<"visited "<<i<<" "<<j<<" "<<flag<<B[i][j]<<"\n";
        return flag;
    }
    void modifyO(int i, int j)
    {
        if( i<0 || i >= m || j<0 || j >= n) 
        {
            return;
        }
        if(B[i][j] == 'O')
        {
            B[i][j] = 'X';
            modifyO(i, j+1);
            modifyO(i+1, j);
            modifyO(i-1, j);
            modifyO(i, j-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        B = move(board);
        m = B.size();
        n = B[0].size();
        visited = move(vector<vector<int>>(m, vector<int>(n, 0)));
        otw = move(vector<vector<bool>>(m, vector<bool>(n, 0)));
        for(int i = 0 ;i < m; ++i)
        {
            for (int j = 0 ; j < n; ++j)
            {
                if(B[i][j] == 'O' && visited[i][j] == 0)
                {
                    if(false == traverseO( i, j))
                    {
                        modifyO(i, j);
                        ;
                    }
                    // ;
                }
            }
        }
        board = move(B);
    }
};
