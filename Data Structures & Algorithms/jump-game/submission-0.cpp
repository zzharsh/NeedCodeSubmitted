class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int maxReach = nums[0];
        int goal = n-1;
        while(i <= maxReach && i < n)
        {
            cout<<i<<" "<<maxReach<<"\n";
            maxReach = max(maxReach, nums[i] + i);
            if(maxReach >= goal) return true;
            i++;
        }
        if(maxReach >= goal) return true;
        return false;
    }
};
