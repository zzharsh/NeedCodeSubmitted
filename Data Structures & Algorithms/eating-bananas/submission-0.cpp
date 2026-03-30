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
            total += nums[i]%k>0 ? 1 : 0;
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
        
        for(int i = 1000000000; i>0; i=i/2)
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
