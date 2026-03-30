class Solution {
    vector<vector<int>> res;
    vector<int> nums;
    int n;
    int t;
public:
    void combine(int i, int curr, vector<int> running)
    {
        if(i >= n)
        {
            return;
        }
        if(nums[i] + curr > t)
        {
            return;
        } 
        if(nums[i] + curr == t)
        {
            running.push_back(nums[i]);
            cout<<"\n Pushing ";
            res.push_back(running);
            return;
        }
        cout<<i<<" ";
        running.push_back(nums[i]);
        curr += nums[i];
        int prev = -1;
        int j = i+1;
        for(j = i+1; j < n && nums[j] + curr <= t; ++j)
        {
            if(prev != nums[j])
            {
                combine(j, curr, running);
                prev = nums[j];
            }
        }
        cout<<endl;
        // j = i + 1;
        // while(j < n && nums[j] == nums[i])
        // {
        //     j++;
        // }
        // if(j == n)
        // {
        //     return;
        // }
        // curr -= nums[i];
        // running.pop_back();
        // combine(j, curr, running);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        nums = move(candidates);
        t = target;
        int p = -1;
        for(int j = 0; j < n ; ++j)
        {
            if(p != nums[j])
            {
                combine(j, 0, {});
                p = nums[j];
            }
        }
        return res;
    }
};
