class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // set<int> S;
        int n = nums.size();
        int ans = 1;
        vector<int> DP(n+1,1);
        // DP[n] = 10004;
        // DP[n-1] = 1;
        for(int i = n-2; i >= 0; --i)
        {
            for(int j = i+1; j < n; ++j)
            {
                if(nums[j] > nums[i])
                {
                    DP[i] = max(DP[i], 1 + DP[j]);
                    ans = max(ans, DP[i]);
                }
            }
            cout<<nums[i]<<" "<<DP[i]<<"\n";
        }
        // ans = DP[0];
        return ans;
    }
};
