class Solution {
public:
    bool check(int i, vector<string>& strs)
    {
        char ch = strs[0][i];
        for(int j = 0; j < strs.size(); ++j)
        {
            string& s = strs[j];
            if(ch != s[i])
            {
                return false;
            }
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        uint64_t minI = strs[0].size();
        for(int i = 0; i < strs.size(); ++i)
        {
            minI = min(strs[i].size(), minI);
        }
        string res = "";
        for(int i = 0; i < minI; ++i)
        {
            if(check(i, strs))
            {
                res = res + strs[0][i];
            }
            else
            {
                return res;
            }
        }
        return res;
    }
};