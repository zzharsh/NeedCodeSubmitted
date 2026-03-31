class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int m1 = nums[0], m2 = nums[0];
        res = max(m1, m2);
        for(int i=1;i<n;++i)
        {
            if(nums[i] == 0)
            {
                // res = max(res, 0);
                m1 = 0;
                m2 = 0;
            }
            else
            {
                if(m1 == 0)
                {
                    m1 = nums[i];
                    m2 = nums[i];
                    // res = max(res, m1);
                }
                else
                {
                    m2 *= nums[i];
                    m1 = max(m1, m2);
                    m1 = max(m1, nums[i]);
                }
            }
            res = max(res, m1);
        }
        return res;
        
    }
};
