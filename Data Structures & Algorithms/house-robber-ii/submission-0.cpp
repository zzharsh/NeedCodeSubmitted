class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> DP(n+1, 0);
        if(n == 1)
        {
            return nums[0];
        }
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }
        DP[n] = 0;
        DP[n-1] = -1 * nums[n-1];
        DP[n-2] = nums[n-2];
        int res = max(abs(DP[n-1]), abs(DP[n-2]));
        for(int i = n - 3; i > 0; --i)
        {
            int a = abs(DP[i+2]);
            int b = abs(DP[i+3]);
            DP[i] = max(a,b) + nums[i];
            res = max(res, DP[i]);
            if(a > b && DP[i+2] < 0)
            {
                DP[i] *= -1;
            }
            if(a < b && DP[i+3] < 0)
            {
                DP[i] *= -1;
            }
        }
        int a = 0, b = 0, i = 0;
        if(DP[i + 2] < 0)
        {
            a = nums[i] + DP[i+2] - nums[n-1];
        }
        else
        {
            a = nums[i] + DP[i+2];
        }
        if(DP[i + 3] < 0)
        {
            b = nums[i] + DP[i+3] - nums[n-1];
        }
        else
        {
            b = nums[i] + DP[i+3];
        }
        DP[i] = max(a,b);
        res = max(DP[i], res);
        return res;
        // int a = abs(DP[i+2]);
        // int b = abs(DP[i+3]);
        // DP[i] = max(a,b) + nums[i];
        // res = max(res, DP[i]);
        // if(a > b && DP[i+2] < 0)
        // {
        //     DP[i][j] *= -1;
        // }
        // if(a < b && DP[i+3] < 0)
        // {
        //     DP[i][j] *= -1;
        // }
    }
};
