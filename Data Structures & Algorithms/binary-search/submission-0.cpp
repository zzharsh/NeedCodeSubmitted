class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        while((s<=e) && (s>=0) && (s<nums.size()) && (e>=0) && (e < nums.size()))
        {
            int m = (s + e)/2;
            if(target == nums[m])
            {
                return m;
            }
            if(target>nums[m])
            {
                s = m+1;
            }
            else
            {
                e = m-1;
            }
        }
        return -1;
    }
};
