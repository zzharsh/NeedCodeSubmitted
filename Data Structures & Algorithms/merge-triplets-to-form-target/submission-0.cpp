class Solution {
public:
    bool checkTriplet(vector<int>& t1, vector<int>& t2, vector<int>& tar)
    {
        bool flag = true;
        for(int i = 0; i < 3; ++i)
        {
            flag = flag && (max(t1[i], t2[i]) == tar[i]);
        }
        return flag;
        // if(max(t1[0], t2[0]) == tar[0])
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        for(int i = 0; i < triplets.size(); ++i)
        {
            for(int j = i+1; j<triplets.size(); ++j)
            {
                if(checkTriplet(triplets[i], triplets[j], target) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
