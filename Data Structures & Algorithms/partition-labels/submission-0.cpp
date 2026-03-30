class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> mp(26, 0);
        for(int i = 0; i < n; ++i)
        {
            mp[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int i = 0;
        while(i < n)
        {
            int curr = 0;
            int e = mp[s[i] - 'a'];
            while(i <= e)
            {
                e = max(e, mp[s[i] - 'a']);
                i++;
                curr++;
            }
            ans.push_back(curr);
        }
        return ans;

    }
};
