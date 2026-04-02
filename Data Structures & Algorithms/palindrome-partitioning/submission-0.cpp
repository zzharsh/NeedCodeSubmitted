class Solution {
    unordered_map<string, bool> DP;
    bool isPal(string s)
    {
        if(s=="") return true;
        if(DP.find(s) != DP.end())
        {
            return DP[s];
        }
        int i = 0,  j = s.size()-1;
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                DP[s] = false;
                return DP[s];
            }
        }
        DP[s] = true;
        return DP[s];
    }
    vector<vector<string>> res;
    void recurse(vector<string> curr, string s)
    {
        if(s=="")
        {
            res.push_back(curr);
            return;
        }
        int n = s.size();
        for(int i = 1; i <= n; ++i)
        {
            string sub1 = s.substr(0, i);
            string sub2 = s.substr(i, n-i);
            if(isPal(sub1))
            {
                curr.push_back(sub1);
                recurse(curr, sub2);
                curr.pop_back();
            }
            printf("i = %d, sub1= %s, sub2= %s \n",
            i, sub1.c_str(), sub2.c_str());
        }
    }
public:
    vector<vector<string>> partition(string s) {
        recurse({}, s);
        return res;
    }
};
