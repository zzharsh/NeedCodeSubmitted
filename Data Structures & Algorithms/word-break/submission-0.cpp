class Solution {
public:
    bool match(string& s, int l, int r, unordered_set<string>& Dict)
    {
        string sub = s.substr(l, r);
        cout<<sub<<" ";
        if(Dict.find(sub) == Dict.end())
        return false;
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Dict;
        int n = s.size();
        for(auto s:wordDict)
        {
            Dict.insert(s);
        }
        vector<int> DP;
        DP.push_back(n);
        for(int i = n - 1; i >= 0; --i)
        {
            bool out = false;
            for(int j = 0; j < DP.size(); ++j)
            {
                // if( i - DP[j] )
                int len = DP[j] - i;
                out = match(s, i, len, Dict);
                cout<<i<<" "<<DP[j]<<" "<<out<<endl;
                
                // if(out == true)
                // {
                //     DP.push_back(i);
                // }
                // <<endl;
            }
            if(out)
            {
                DP.push_back(i);
                if(i==0) return true;
            }
        }
        return false;
    }
};
