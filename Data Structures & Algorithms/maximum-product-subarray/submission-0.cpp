class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> forward, backward;
        int n = nums.size();
        for (int i=0;i<n;++i)
        {
            if(i==0)
            {
                forward.push_back(nums[i]);
            }
            else if(nums[i] == 0)
            {
                forward.push_back(0);
            }
            else
            {
                forward.push_back(forward[i-1] * nums[i]);
            }
        }
        return 0;
        
    }
};
