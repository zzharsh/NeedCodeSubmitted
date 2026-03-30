class Solution {
public:
    bool checkAns(vector<int> mp, char* sp, int sz)
    {
        vector<int> mp2(26, 0);
        for(int i = 0; i < sz; ++i)
        {
            mp2[*(sp + i) - 'a']++;
            cout<<*(sp+i);
        }
        cout<<" ";
        for(int i = 0; i < 26; ++i)
        {
            if(mp[i] != mp2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> mp(26, 0);
        char* s2p = &s2[2];
        for(int i = 0; i < s1.size(); ++i)
        {
            mp[s1[i] - 'a']++;
        }
        for(int i = 0; i + s1.size() < s2.size() + 1; ++i)
        {
            // cout<<i<<" "<<i+s1.size()<<" "<<s2.size()<<"\n";
            if(checkAns(mp, &s2[i], s1.size()))
            {
                return true;
            }
        }
        // cout<<s1<<" "<<*s2p<<*(s2p+1)<<" ";
        return false;
    }
};
