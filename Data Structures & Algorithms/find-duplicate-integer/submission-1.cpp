class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i;
        for(i=0;i<n;++i)
        {
            int x = nums[i]<0?nums[i]*-1:nums[i];
            if(nums[x-1] < 0)
            {
                return x;
            }
            nums[x-1] = -1 * nums[x-1];
        }
        return 0;
    }
};
