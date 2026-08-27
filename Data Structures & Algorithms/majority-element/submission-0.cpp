class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curr, currCount, res=nums[0], resCount=0, n =nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(resCount > n/2)
            {
                return res;
            }
            if(curr == nums[i])
            {
                currCount++;
                if(currCount > resCount)
                {
                    res = curr;
                    resCount = currCount;
                }
            }
            else
            {
                curr = nums[i];
                currCount = 0;
            }
        }
        return res;

    }

};