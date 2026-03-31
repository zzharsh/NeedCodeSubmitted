class Solution {
public:
    int digitSquareSum(int n)
    {
        int su = 0;
        while( n > 0)
        {
            su += (n%10) * (n%10);
            n = n/10;
        }
        return su;
    }
    bool isHappy(int n) {
        int comp = digitSquareSum(n);
        int cnt = 0;
        if(comp==1) return true;
        while(n!=1)
        {
            n = digitSquareSum(n);
            cout<<n<<" "<<comp<<"\n";
            cnt++;
            if(n == comp)
            {
                return false;
            }

        }
        return true;
    }
};
