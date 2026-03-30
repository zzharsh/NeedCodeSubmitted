class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> DP(2,0);
        int n = cost.size();
        int i = n-1;
        // Initialize DP
        if(cost.size() < 3)
        {
            return min(cost[0], cost[1]);
        }
        DP[0] = cost[i--];
        DP[1] = cost[i--];
        for(int j = 0; j< 2; ++j)
        {
            cout<<DP[j]<<" ";
        }
        for(;i>=0;--i)
        {
            int costi = cost[i] + min(DP[0], DP[1]);
            DP[0] = DP[1];
            DP[1] = costi;
            cout<<DP[1]<<" ";
        }
        return min(DP[0], DP[1]);

        // return 0;
    }
};
