class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), S=0;
        for(auto x:nums)
        {
            S += x;
        }
        return ((n*(n+1)) / 2 - S);
    }
};
