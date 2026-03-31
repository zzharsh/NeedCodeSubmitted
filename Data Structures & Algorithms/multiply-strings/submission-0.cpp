class Solution {
public:
    string add(string num1, string num2, int k)
    {
        if(num1 == "")
        {
            return num2;
        }
        while(k>0)
        {
            num2 = num2 + "0";
            k--;
        }
        string ans = "";
        int i, j, s=0, c=0, n = num1.size()-1, m = num2.size()-1;
        cout<<" add "<<num1<<" "<<num2<<" ";
        for(i=0;i<=n;++i)
        {
            s = (num1[n-i] -'0') + (num2[m-i] - '0') + c;
            c = s/10;
            s = s%10;
            ans = to_string(s) + ans;
            // cout<<'s'<<s<<'c'<<c;
            cout<<" add "<<ans<<" ";
            // << i<<" "<<n-i<<m-i<<" ";
        }        
        for(;i<=m;++i)
        {
            // cout<<"\n";
            s = (num2[m-i]-'0') + c;
            c = s/10;
            s = s%10;
            ans = to_string(s) + ans;
            // cout<<'s'<<s<<'c'<<c;
            cout<<" add "<<ans<<" " ;
            // << i<<" "<<n-i<<m-i<<" ";
        }
        if(c>0)
        {
            ans = to_string(c) + ans;
        }
        
        return ans;
    }
    string multiply(string num1, string num2) {
        string ans = "";
        int i, j, n=num1.size(), m = num2.size(), carry = 0;
        for(i=n-1;i>=0;--i)
        {
            string temp = "";
            for(j=m-1;j>=0;--j)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = mul/10;
                mul = mul%10;
                temp  = to_string(mul) + temp;
            }
            if(carry>0)
                temp = to_string(carry) + temp;
            cout<<temp<<" "<< ans<<" \n";
            carry = 0;
            ans = add(ans, temp, n-1-i);
        }
        return ans;
    }
};
