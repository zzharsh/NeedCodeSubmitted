class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2,0);
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); ++i)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                answer[0] = mp[target-nums[i]];
                answer[1] = i;
                return answer;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return answer;
        
    }
};
