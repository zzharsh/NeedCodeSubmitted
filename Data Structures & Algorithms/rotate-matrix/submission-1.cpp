class Solution {
public:
    void swap(int& a, int& b)
    {
        int c = a;
        a = b;
        b = c;
    }
    void rotate(vector<vector<int>>& matrix) {
        // Reverse
        int n = matrix.size();
        for(int i = 0;i<n/2;++i)
        {
            for(int j = 0; j< n; ++j)
            {
                swap(matrix[i][j], matrix[n-1 - i][j]);
            }
        }
        // Transpose
        for(int i = 0; i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                cout<<"Swapping "<<i<<j<<" to "<<j<<i<<"\n";
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
