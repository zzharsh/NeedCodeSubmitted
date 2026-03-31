class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int running = nums[0];
        int mxsub = nums[0];
        for (int i =1;i<n;++i)
        {
            mxsub = max(mxsub, running);
            if(running == 0)
            {
                running = nums[i];
                mxsub = max(mxsub, running);
                // mxsub = max(mxsub, nums[i]);
            }
            else
            {
                running *= nums[i];
                mxsub = max(mxsub, running);
                mxsub = max(mxsub, nums[i]);
            }
        }
        return mxsub;
        
    }
};
