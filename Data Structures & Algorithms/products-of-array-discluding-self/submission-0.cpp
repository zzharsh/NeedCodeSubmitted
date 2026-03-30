class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> fow(nums.size(),1), back(nums.size(),1), result(nums.size());
        fow[0]=nums[0];
        back[nums.size()-1]=nums[nums.size()-1];
        for(int i=1; i<nums.size();++i)
        {
            fow[i] = fow[i-1] * nums[i];
            back[nums.size()-1-i] = back[nums.size()-i]*nums[nums.size()-1-i];
        }
        for(int i=0;i<nums.size();++i)
        {
            if(i==0)
            {
                result[i] = back[i+1];
            }
            else if(i==nums.size()-1)
            {
                result[i] = fow[i-1];
            }
            else 
            {
                result[i]= back[i+1]*fow[i-1];
            }
        }
        return result;

    }
};
