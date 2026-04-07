class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> DP(2,vector<int>(n+1, 0));
        if(n == 1)
        {
            return nums[0];
        }
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }
        DP[0][n] = 0;
        DP[1][n] = 0;
        DP[0][n-1] = nums[n-1];
        DP[1][n-1] = 0;
        DP[0][n-2] = nums[n-2];
        DP[1][n-2] = nums[n-2];
        int res = max(abs(DP[0][n-1]), abs(DP[0][n-2]));
        res = max(res, abs(DP[1][n-2]));
        res = max(abs(DP[1][n-1]), res);
        for(int i = n - 3; i > 0; --i)
        {
            res = max(res, nums[i]);
            DP[0][i] = max(DP[0][i+2], DP[0][i+3]) + nums[i];
            DP[1][i] = max(DP[1][i+2], DP[1][i+3]) + nums[i];
            res = max(DP[0][i], res);
            res = max(DP[1][i], res);
            cout<<res<<" ";
            // printf(" DP[%d] = %d\n", i, DP[i]);
        }
        DP[1][0] = max(DP[1][2], DP[1][3]) + nums[0];
        res = max(DP[0][0], res);
        res = max(DP[1][0], res);
        cout<<res<<endl;
        string pri1 = "", pri2 = "";
        for(int i = 0; i < n; ++i)
        {
            cout<<nums[i]<<" ";
            pri1 = pri1 + to_string(DP[0][i]) + " ";
            pri2 = pri2 + to_string(DP[1][i]) + " ";
        }
        cout<<endl<<pri1<<endl<<pri2;
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
