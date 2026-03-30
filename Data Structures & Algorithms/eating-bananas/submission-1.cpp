class Solution {
public:
    vector<int> nums;
    int hr;
    bool CheckIfPossible(int k)
    {
        int total = 0;
        for(int i=0;i<nums.size();++i)
        {
            total += nums[i]/k;
            total += (nums[i] - (nums[i]/k)*k)>0 ? 1 : 0;
            // cout<<"H "<<total<<" "<<nums[i] - (nums[i]/k)*k<<" "<<nums[i]<<" "<<(nums[i]/k)*k<<"\n";
            if(total>hr)
            {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        nums = piles;
        hr = h;
        int s=1, e=1000000000;
        int res = -1;
        int mx = 0;
        for (auto x:piles)
            mx = max(x, mx);
        e = mx+1;
        for(int i = mx+1; i>0; i=i/2)
        {
            int m = (s+e)/2;
            if(CheckIfPossible(m) == true)
            {
                res = m;
                e = m;
            }
            else
            {
                s = m;
            }
            cout<<m<<" "<<i<<" "<<CheckIfPossible(m)<<"\n";
        }
        return res;

    }
};
