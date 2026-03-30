class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        long long tSum = 0;
        unordered_map<long long, int> S1, S2;
        S1[0] = 1;
        for(int i = 0; i < n; ++i)
        {
            for(auto it = S1.begin(); it != S1.end(); ++it)
            {
                tSum = it->first + nums[i];
                S2[tSum] = it->second + S2[tSum];
                tSum = it->first - nums[i];
                S2[tSum] = it->second + S2[tSum];
            }
            S1 = S2;
            for(auto it = S2.begin(); it != S2.end(); ++it)
            {
                cout<<it->first<<"->"<<it->second<<" ";
            }
            cout<<"\n";
            S2 = move(unordered_map<long long, int>());
        }
        return S1[target];
    }
};
