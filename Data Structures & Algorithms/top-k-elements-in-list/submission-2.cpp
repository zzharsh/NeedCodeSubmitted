class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i=0;i<nums.size();++i)
        {
            count[nums[i]]++;
        }
        multimap<int,int> ktop;
        for(auto it: count)
        {
            ktop.insert(make_pair(it.second,it.first));
        }
        vector<int> result(k,0);
        int l=0;
        for(auto itr=ktop.rbegin(); itr!=ktop.rend(); itr++)
        {
            // cout<<itr->second<<" "<<l<<" ";
            if(l<k)
            {
                result[l]=itr->second;
                // cout<<itr->second<<" "<<l<<" ";
                l++;
            }
        }
        return result;
    }
};
