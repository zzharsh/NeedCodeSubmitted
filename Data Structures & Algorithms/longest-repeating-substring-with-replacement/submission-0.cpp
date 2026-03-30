class Solution {
public:
    int maxCount(int* mp, int sz = 26)
    {
        int mx = 0;
        for(int i = 0; i < sz; ++i)
        {
            mx = max(mx, mp[i]);
        }
        return mx;
    }
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size(), res = 0;
        if (n==0) return 0;
        int mp[26] = {0};
        mp[s[r] - 'A']++;
        while(l < n && r < n)
        {
            int windowSize = (r - l + 1);
            if( windowSize - maxCount(mp) <= k)
            {
                r++;
                if(r < n) mp[s[r] - 'A']++;
                res = max(res, windowSize);
            }
            else
            {
                mp[s[l] - 'A']--;
                l++;
            }
        }
        return res;
    }
};
