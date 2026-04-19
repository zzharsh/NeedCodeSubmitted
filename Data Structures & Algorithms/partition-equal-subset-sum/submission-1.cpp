class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long sum = 0, n = nums.size(), i;
        for (i = 0; i < n; ++i)
        {
            sum += nums[i];
        }
        if(sum % 2 != 0)
        {
            return false;
        }
        vector<bool> DP1(sum / 2 + 1, false), DP2(sum / 2 + 1, false);
        cout<<sum<<endl;
        // return false;
        for(i = n-1; i >= 0; --i)
        {
            // printf("%d | ", i, nums[i]);
            for(int j = 0; j < sum/2 + 1; ++j)
            {
                if( j == nums[i])
                {
                    DP1[j] = true;
                }
                if (true == DP2[j])
                {
                    DP1[j] = true;
                    if(nums[i] + j < sum / 2 + 1)
                    {
                        DP1[nums[i] + j] = true;
                    }
                }
                // printf("%d:%d %d, ", j, static_cast<int>(DP1[j]), nums[i] + j);
                if(DP1[sum/2] == true)
                {
                    return true;
                }
            }
            cout<<endl;
            // return false;
            DP2 = DP1;
            // DP1 = std::move(vector<bool>(sum / 2 + 1, false));
        }
        return false;
    }
};
