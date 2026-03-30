class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char, int> sm;
        for(int i=0;i<s.size();++i)
        {
            sm[s[i]]++;
        }
        for(int i=0;i<t.size();++i)
        {
            if(sm.find(t[i])!=sm.end())
            {
                sm[t[i]]--;
                if(sm[t[i]] == 0 )
                {
                    sm.erase(t[i]);
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
