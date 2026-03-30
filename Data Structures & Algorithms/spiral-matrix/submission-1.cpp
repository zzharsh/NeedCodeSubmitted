class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        // traverse a parimiter
        int i, j, nn, nm, nmz, nnz, perimeter = 100, total;
        nm = matrix.size();
        nn = matrix[0].size();
        nmz = 0;
        nnz = 0;
        total = nm * nn;
        i = 0;
        j = 0;
        vector<int> ans;
        while(total > 0 && perimeter > 0)
        {
            perimeter--;
            while(total > 0 && j < nn)
            {
                ans.push_back(matrix[i][j]);
                cout<<i<<" "<<j<<"\n";
                ++j;
                --total;
            }
            cout<<total<<"\n";
            j = nn-1;
            i++;
            while(total > 0 && i < nm)
            {
                ans.push_back(matrix[i][j]);

                cout<<i<<" "<<j<<"\n";
                ++i;
                --total;
            }
            cout<<total<<"\n";
            i = nm-1;
            j--;
            while(total > 0 && j >= nnz)
            {
                ans.push_back(matrix[i][j]);

                cout<<i<<" "<<j<<"\n";
                --j;
                --total;
            }
            cout<<total<<"\n";
            i--;
            j = nnz;
            while(total > 0 && i > nmz)
            {
                ans.push_back(matrix[i][j]);

                cout<<i<<" "<<j<<"\n";
                --i;
                --total;
            }
            cout<<total<<"\n";

            i = nmz+1;
            j = nnz+1;
            nmz++;
            nnz++;
            nn--;
            nm--;
        }
        return ans;
    }
};
