class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0, n = nums.size()-1, sz = nums.size();
        if (sz==1)
        {
            return nums[0];
        }
        int res = -1;
        for(int k = nums.size();k>0;k/=2)
        {
            int m = (i + n)/2;
            cout<<i<<" "<<m<<" "<<n<<" "<<nums[i]<<" "<<nums[m]<<" "<<nums[n]<<"\n";
            if(nums[i] <= nums[m])
            {
                int left = i-1 < 0 ? sz-1 : i-1;
                int right = i+1 == sz ? 0: i+1;

                if(nums[i]<nums[left] && nums[i] < nums[right])
                {
                    return nums[i];
                }
                i = m+1 == sz ? 0 : m+1;
                // cout<<"increase i";
            }
            else
            {
                int left = m-1 < 0 ? sz-1 : m-1;
                int right = m+1 == sz ? 0: m+1;

                if(nums[m]<nums[left] && nums[m] < nums[right])
                {
                    return nums[m];
                }
                n = m-1 < 0 ? sz-1 : m-1;
                // cout<<" decrease n";
            }
            res = m;
        }
        return nums[res];
    }
};
