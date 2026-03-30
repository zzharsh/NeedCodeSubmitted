class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0, e = matrix.size() * matrix[0].size() -1, sz = matrix.size() * matrix[0].size();
        int m = matrix.size(), n = matrix[0].size();
        while((s<=e) && (s>=0) && (s<sz) && (e>=0) && (e<sz))
        {
            int mid = (e+s)/2;
            int i = mid / n, j = mid % n;
            // cout<<i<<" "<<j<<"\n";
            if(target == matrix[i][j])
            {
                return true;
            }
            if(target > matrix[i][j])
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        return false;
    }
};
