class Solution {
public:
    void swap(int i, int j, vector<int>& nums)
    {
        if(i==j)
        {
            return;
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    int removeElement(vector<int>& nums, int val) {
        int k = 0, i=0, j=0, n = nums.size();
        while(j < n)
        {
            while(j < n && nums[j] == val)
            {
                ++j;
            }
            if(j < n)
            {
                swap(i,j,nums);
                ++i;
                ++k;
                ++j;
            }
        }
        return k;
    }
};