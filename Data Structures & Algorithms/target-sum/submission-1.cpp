class Solution {
public:
    int ans = 0;
    vector<int> values;
    int n, t;
    void recurse(int i, int curr)
    {
        cout<<i<<" "<<curr<<"\n";
        if(i==n)
        {
            if(curr == t)
            {
                ans++;
            }
        }
        if(i<0 || i > n) return;
        // curr -= values[i];
        recurse(i+1, curr - values[i]);
        recurse(i+1, curr + values[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        values = move(nums);
        n = values.size();
        t = target;
        recurse(0, 0);
        nums = move(values);
        // return 0;
        return ans;
    }
};
