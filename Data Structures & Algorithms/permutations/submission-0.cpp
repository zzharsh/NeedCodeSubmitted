class Solution {
public:
    vector<vector<int>> ans;
    vector<int> orig;
    int n = 0;
    void permutations(vector<bool> remaining, int i, vector<int> running)
    {
        cout<<i<<" "<<running.size()<<"\n";
        if(i==n)
        {
            ans.push_back(running);
            return;
        }
        for (int k = 0; k< n; ++k)
        {
            if(remaining[k])
            {
                running.push_back(orig[k]);
                remaining[k] = false;
                permutations(remaining, i+1, running);
                running.pop_back();
                remaining[k] = true;
            }
            
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<bool> remaining(n,true);
        orig = nums;     
        // for(int i = 0; i<n;++i)
        // {
        //     remaining.insert(nums[i]);
        // }
        permutations(remaining, 0, vector<int>());
        return ans;
    }
};
