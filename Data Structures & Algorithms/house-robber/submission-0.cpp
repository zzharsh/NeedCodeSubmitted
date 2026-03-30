class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), i=0, res = 0;
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0], nums[1]); 
        }
        vector<int> DP(n, 0);
        DP[0] = nums[i++];
        DP[1] = nums[i++];
        DP[2] = nums[i++] + DP[0];
        cout<<DP[0]<<" "<<DP[1]<<" ";
        for(; i < n; ++i)
        {
            DP[i] = nums[i] + max(DP[i-2], DP[i-3]);
            cout<<DP[i]<<" ";
        }
        return max(DP[n-1], DP[n-2]);
    }
};
