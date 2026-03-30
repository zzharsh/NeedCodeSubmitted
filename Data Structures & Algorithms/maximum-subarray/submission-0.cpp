class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0], n = nums.size();
        int running = nums[0];
        int mxsub = nums[0];
        // mx = max(nums[0], mx);
        for (int i=1;i<n;++i)
        {
            running = running + nums[i];
            running = max(running, nums[i]);
            mxsub = max(mxsub, running);
            // mxsub = max
        }
        return mxsub;

    }
};
