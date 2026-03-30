class Solution {
public:
    int countSubstrings(string s) {
        int lo = 0, ro = 0, n = s.size(), le = 0, re = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            lo = i;
            ro = i;
            le = i-1;
            re = i;
            // ans++;
            int cnt = 0;
            bool fE = true, fO = true;
            cout<<i<<" : ";
            while(cnt++ < 100 && (fE || fO))
            {
                if(le >= 0 && re < n && s[le] == s[re])
                {
                    ans++;
                    cout<<" le "<<le<<" re "<<re<<" "<<ans<<" | ";
                    le--;
                    re++;
                }
                else
                {
                    fE = false;
                }
                if(lo >= 0 && ro < n && s[lo] == s[ro])
                {
                    ans++;
                    cout<<" lo "<<lo<<" ro "<<ro<<" "<<ans<<" | ";
                    lo--;
                    ro++;
                }
                else
                {
                    fO = false;
                }
            }
            cout<<"\n";
        }
        return ans;
    }
};
