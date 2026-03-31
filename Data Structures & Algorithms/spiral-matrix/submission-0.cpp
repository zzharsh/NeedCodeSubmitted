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
        while(total > 0 && perimeter > 0)
        {
            perimeter--;
            while(j < nn)
            {
                cout<<i<<" "<<j<<"\n";
                ++j;
                --total;
            }
            cout<<"\n";
            j = nn-1;
            i++;
            while(i < nm)
            {
                cout<<i<<" "<<j<<"\n";
                ++i;
                --total;
            }
            cout<<"\n";
            i = nm-1;
            j++;
            while(j > nnz)
            {
                cout<<i<<" "<<j<<"\n";
                --j;
                --total;
            }
            cout<<"\n";

            i = nmz + 1;
            j = nnz + 1;
            while(i > nmz)
            {
                cout<<i<<" "<<j<<"\n";
                --i;
                --total;
            }
            i = nmz+1;
            j--;
            nmz++;
            nnz++;
            nn--;
            nm--;
        }
        return {};
    }
};
