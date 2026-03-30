class Solution {
public:
    bool invalidT(vector<int>& trip, vector<int>& tar)
    {
        for(int i = 0; i < 3; ++i)
        {
            if(trip[i] > tar[i]) return false;
        }
        return true;
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool flag[] = {false, false, false};
        bool ans = flag;
        for(int i = 0; i < triplets.size(); ++i)
        {
            if(invalidT(triplets[i], target))
            {
                for(int j = 0 ; j < 3; ++j)
                {
                    flag[j] = flag[j] || (triplets[i][j] == target[j]);
                }
            }
        }
        for(int i = 0; i < 3; ++i)
        {
            ans = ans && flag[i];
        }
        return ans;

    }
};
