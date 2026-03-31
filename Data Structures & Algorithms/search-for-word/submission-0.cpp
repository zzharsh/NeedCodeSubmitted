class Solution {
public:
    unordered_set<int> visited;
    string W;
    vector<vector<char>> B;
    int m , n;
    bool DFS(int i, int j, int w)
    {
        if(w >= W.size())
        {
            return true;
        }
        if(i < 0 || i >= m || j < 0 || j >= n)
        {
            return false;
        }
        cout<<B[i][j]<<" ";
        if(B[i][j] != W[w])
        {
            return false;
        }
        if(visited.find(i * n + j) != visited.end())
        {
            return false;
        }
        visited.insert(i * n + j);
        bool flag = false;
        flag = flag || DFS(i+1, j, w+1);
        if(flag == true) return true;
        flag = flag || DFS(i, j+1, w+1);
        if(flag == true) return true;
        flag = flag || DFS(i-1, j, w+1);
        if(flag == true) return true;
        flag = flag || DFS(i, j-1, w+1);
        if(flag == true) return true;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool flag = false;
        W = move(word);
        m = board.size();
        n = board[0].size();
        B = move(board);
        for(int i = 0 ;i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                // cout<<B[i][j]<<" "<<
                if(B[i][j] == W[0])
                {
                    visited.clear();
                    cout<<B[i][j]<<" ";
                    if(DFS(i, j, 0) == true)
                    {
                        return true;
                    }
                    cout<<"\n";
                }
            }
        }
        return false;
    }
};
