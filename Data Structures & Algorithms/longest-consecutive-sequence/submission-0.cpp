class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i=0;i<nums.size();++i)
        {
            count[nums[i]] = 1;
        }
        for(auto it = count.begin(); it!=count.end(); ++it)
        {
            int first = it->first -1; 
            while(count.find(first)!=count.end() && count[first] != 0)
            {
                count[first-1] += count[first];
                cout<<first<<" "<<count[first]<<"\n";
                count[first] = 0;
                // first--;
            }
        }
        int result = 1;
        for(auto it = count.begin(); it!=count.end(); ++it)
        {
            result = max(result, it->second);
        }
        return result;
    }
};
