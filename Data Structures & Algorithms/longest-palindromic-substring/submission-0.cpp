class Solution {
public:
    string str;
    int n;
    string growPalindrome(int s, int e, string curr)
    {
        // cout<<s<<" "<<e<<" ";
        if(s < 0 || e >= n) return curr;
        // cout<<"Running"<<"\n";
        // return "" + string(1,'a');
        if(str[s] == str[e])
        {
            if(s != e)
            {
                curr = string(1, str[s]) + curr + string(1,str[e]);
            }
            else
            {
                curr = string(1, str[s]);
            }
            return growPalindrome(s-1, e+1, curr);
        }
        else
        {
            return curr;
        }
    }
    string longestPalindrome(string s) {
        str = s;
        int i = 0;
        n = s.size();
        string ans = "";
        for(i = 0; i < s.size(); ++i)
        {
            cout<<s[i]<<" ";
            string s1 = growPalindrome(i,i,"");
            string s2 = growPalindrome(i,i+1,"");
            cout<<s1<<" "<<s2<<"\n";
            ans = s1.size() > s2.size() ? 
                  s1.size() > ans.size() ? s1 : ans : 
                  s2.size() > ans.size() ? s2 : ans; 
        }
        return ans;
    }
};
