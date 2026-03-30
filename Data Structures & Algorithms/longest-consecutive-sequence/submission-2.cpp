class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> start;
        for(int i=0;i<nums.size();++i)
        {
            count[nums[i]] = 1;
        }
        for(auto it = count.begin(); it!=count.end(); ++it)
        {
            if(count.find(it->first-1)==count.end())
            {
                start.push_back(it->first);
            }
        }
        int result = 0;
        for(auto ele:start)
        {
            int c = 0, f=ele;
            while(count.find(f)!=count.end())
            {
                // cout<<f<<" ";
                ++f;
                ++c;
            }
            // while(count.find(f)!=count.end());
            // {
            //     ++f;
            //     c++;
            // }
            result = max(result, c);
        }
        return result;
    }
};
