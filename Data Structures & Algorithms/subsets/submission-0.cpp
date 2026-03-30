class Solution {
public:
    vector<vector<int>> ans;
    vector<int> m_nums;
    int n;
    int counter = 100;
    void subs(vector<int> current, int i)
    {
        if(i>=n) return;
        current.push_back(m_nums[i++]);
        for(;i<n;++i)
        {
            subs(current, i);
        }
        ans.push_back(current);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        m_nums = nums;
        n = nums.size();
        for(int i = 0; i< n;++i)
        {
            subs({},i);
        }
        ans.push_back({});
        return ans;
    }
};
