class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i=0;i<nums.size();++i)
        {
            count[nums[i]]++;
        }
        map<int,int> ktop;
        for(auto it: count)
        {
            ktop[it.second]=it.first;
        }
        vector<int> result(k,0);
        int l=0;
        for(auto itr=ktop.rbegin(); itr!=ktop.rend(); itr++)
        {
            cout<<itr.first;
            // if(l<k)
            // {
            //     l++;
            //     result.push_back(it.second);
            // }
        }
        return result;
    }
};
