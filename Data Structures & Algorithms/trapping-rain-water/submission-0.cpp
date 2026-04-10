class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n+1, 0), right(n+1, 0), fills(n);
        for(int i = 0; i < n; ++i)
        {
            left[i + 1] = max(left[i], nums[i]);
        }
        for(int i = n-1; i >= 0; i--)
        {
            right[i] = max(right[i+1], nums[i]);
        }
        for(int i = 0; i < n; ++i)
        {
            int li = i;
            int ri = i+1;
            fills[i] = max(0, min(right[ri], left[li]) - nums[i]);
        }
        int res = 0;
        string l = "", r = "", f = "";
        for(int i = 0; i < n; ++i)
        {
            res += fills[i];
            l = l + to_string(left[i+1]) + " ";
            r = r + to_string(right[i]) + " ";
            f = f + to_string(fills[i]) + " "; 
        }
        cout<<l<<endl<<r<<endl<<f;
        return res;
    }
};
