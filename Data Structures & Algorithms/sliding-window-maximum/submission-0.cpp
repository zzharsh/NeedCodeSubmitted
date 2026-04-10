class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> heap;
        int n = nums.size(), i;
        for(i = 0; i < k; ++i)
        {
            heap.insert(nums[i]);
        }
        res.push_back(*(heap.rbegin()));
        for(int j = 0; i < n; ++i)
        {
            auto it = heap.find(nums[j++]);
            heap.erase(it);
            heap.insert(nums[i]);
            res.push_back(*(heap.rbegin()));

        }
        return res;

    }
};
