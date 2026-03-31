class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, ans = 0, n = s.size();
        unordered_set<char> S;
        while(j<n)
        {
            cout<<i<<" "<<j<<"\n";
            if(S.find(s[j]) == S.end())
            {
                S.insert(s[j]);
                int S_Size = S.size();
                ans = max(ans, S_Size);
                ++j;
            }
            else
            {
                while(s[i] != s[j])
                {
                    
                    S.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;

        
    }
};
