class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> S;
        int n = nums.size();
        for(int i=0;i<n;++i)
        {
            S.insert(nums[i]);
            if(i>=k)
            {
                auto it = S.begin();
                // it--;
                S.erase(it);
            }
        }
        for(auto it=S.begin(); it!=S.end(); ++it)
        {
            cout<<*it<<" ";
        }
        auto it = S.begin();
        // it--;
        return *it;
    }
};
