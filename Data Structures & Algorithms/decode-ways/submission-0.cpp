class Solution {
public:
    bool isValid(string x)
    {
        cout<<"Called isValid with "<<x<<" ";
        int y = stoi(x);
        printf("Converted %s --> %d: ", x.c_str(), y);
        if(x[0]=='0')
        {
            cout<<0<<endl;
            return false;
        }
        else if(y > 27 || y < 1)
        {
            cout<<0<<endl;
            return false;
        }
        cout<<1<<endl;
        return true;
    }
    int numDecodings(string s) {
        int res = 0;
        int n = s.size();
        vector<int> DP(n+1, 0);
        DP[n-1] = s[n-1] == '0' ? 0 : 1;
        DP[n] = 1;
        for(int i = n-2; i >= 0; --i)
        {
            string sub1 = "";
            sub1 += s[i]; 
            // sub1 += s[i];
            string sub2 = sub1 + s[i+1];
            cout<<i<<" "<<sub1<<" "<<sub2<<" "<<s[i]<<endl;
            if(isValid(sub1))
            {
                DP[i] += DP[i+1];
            }
            if(isValid(sub2))
            {
                DP[i] += DP[i+2];
            }

        }
        return DP[0];
    }
};
