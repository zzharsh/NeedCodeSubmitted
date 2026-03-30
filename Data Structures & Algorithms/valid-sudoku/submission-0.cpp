class Solution {
    int row[10][10] = {0}, col[10][10] = {0}, grid[10][10] ={0};
    bool checkIfValid(int x, int i, int j, int k)
    {
        // cout<< "check"<<row[i][x]<<" "<<col[j][x]<<" "<<grid[k][x];
        if ((row[i][x] > 0) || (col[j][x] > 0) || (grid[k][x] > 0 ))
        {
            return false;
        }
        else
            return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r=1, c=1, g=1;
        for (int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                cout<<" | ";
                int gg = (i/3) * 3 + j/3 +1;
                // cout<<i+1<<" "<<j+1<<" "<<gg;
                if (board[i][j]!='.')
                {
                    int num = board[i][j] - '0';
                    
                    // cout<<num<<" "<<i+1<<" "<<j+1<<" "<<gg;
                    if (true == checkIfValid(num, i+1, j+1, gg))
                    {
                        row[i+1][num] = 2;
                        col[j+1][num] = 2;
                        grid[gg][num] = 2;
                    }
                    else
                    {
                        return false;;
                    }
                }
            }
            cout<<"\n";
        }
        return true;
    }
};
