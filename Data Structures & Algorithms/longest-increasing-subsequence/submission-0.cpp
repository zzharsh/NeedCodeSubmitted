class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> S;
        int n;
        for(auto x:nums)
        {
            S.insert(x);
            cout<<(distance(S.end(), S.upper_bound(x)))<<(*S.upper_bound(x))<<"\n";
        }
        return 0;
    }
};
