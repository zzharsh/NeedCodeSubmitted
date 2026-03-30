class Solution {
public:
    bool isPalindrome(string s) {
        int i, j, n;
        n=s.size();
        i = 0;
        j = n-1;
        bool res = true;

        while(i<j)
        {
            
            while(false == isalnum(s[i]))
            {
                i++;
                cout<<s[i]<<" "<<s[j]<<" "<<isalnum(s[i])<<" i "<<"\n";
            }
            while(false == isalnum(s[j]))
            {
                j--;
                cout<<s[i]<<" "<<s[j]<<" "<<isalnum(s[i])<<" j "<<"\n";
            }
            if(i<j)
            {
                if(tolower(s[i]) != tolower(s[j]))
                {
                    
                    res = false;
                    return res;
                }
                else
                {
                    i++;
                    --j;
                }
            }
        }
        return res;
    }
};
