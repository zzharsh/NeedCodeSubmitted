class Solution {
public:
    int max4(int a, int b, int c, int d)
    {
        int res = a;
        res = max(b, res);
        res = max(c, res);
        res = max(d, res);
        return res;
    }
    int min4(int a, int b, int c, int d)
    {
        int res = a;
        res = min(b, res);
        res = min(c, res);
        res = min(d, res);
        return res;
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int m1 = nums[0], m2 = nums[0];
        // res = max(m1, m2);
        for(int i=1;i<n;++i)
        {
            int temp = m1;
            m1 = max4(nums[i], nums[i], m1 * nums[i], m2*nums[i]);
            m2 = min4(nums[i], nums[i], m2*nums[i], temp * nums[i]);
            res = max(m1, res);
            // m1 = max(nums[i], m1);
            // m1 = max(m1, temp);
            // m1 = max(m1, m2 * nums[i]);
            // // temp = m2 * nums[i];
            // m2 = min(m2, temp);
            // m2 = min(nums[i], m2);
            // res = max(m1, res);
        }
        return res;
        
    }
};
