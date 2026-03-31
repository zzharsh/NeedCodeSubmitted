class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0, n = nums.size()-1, sz = nums.size();
        int res = -1;
        for(int k = nums.size();k>0;k/=2)
        {
            int m = (i + n)/2;
            cout<<i<<" "<<m<<" "<<n<<" "<<nums[i]<<" "<<nums[m]<<" "<<nums[n]<<"\n";
            int left = m-1 < 0 ? sz-1 : m-1;
            int right = m+1 == sz ? 0: m+1;
            if(nums[m]<nums[left] && nums[m] < nums[right])
            {
                return nums[m];
            }
            if(nums[i] <= nums[m])
            {
                i = m+1 == sz ? 0 : m+1;
                cout<<"increase i";
            }
            else
            {
                n = m-1 < 0 ? sz-1 : m-1;
                cout<<" decrease n";
            }
            res = m;

        }
        return nums[res];
    }
};
