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
        unordered_set<int> comp;
        comp.insert(digitSquareSum(n));
        n = digitSquareSum(n);
        int cnt = 0;
        if(n==1) return true;
        while(n!=1)
        {
            n = digitSquareSum(n);
            cout<<n<<" "<<"\n";
            cnt++;
            if(comp.find(n) != comp.end())
            {
                return false;
            }
            else
            {
                comp.insert(n);
            }
            

        }
        return true;
    }
};
