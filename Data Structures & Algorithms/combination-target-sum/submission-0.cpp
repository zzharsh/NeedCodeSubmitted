class Solution {
public:
    int t;
    vector<vector<int>> ans;
    vector<int>* values;
    void print(const vector<int>& a)
    {
        for(auto x:a)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void func(int i, vector<int> running, int rSum)
    {
        print(running);
        if(rSum > t) return;
        if(rSum == t)
        {
            ans.push_back(running);
            cout<<"Pushing "<<rSum<<"\n";
            return;
        }
        int s = 0;
        for (int j = i; j < values->size(); ++j)
        {
            s = rSum + (*values)[j];
            vector<int> curRunning = running;
            curRunning.push_back((*values)[j]);
            if(s<=t)
            {
                func(j, curRunning, s);
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums[0] > target) return {};
        t = target;
        values = (vector<int>*)((void*) &nums);
        for(int i = 0; i < values->size(); ++i)
        {
            func(i, {(*values)[i]}, (*values)[i]);
        }
        return ans;
    }
};
