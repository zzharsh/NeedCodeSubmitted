class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
        {
            return 1.0;
        }
        if(n==1)
        {
            return x;
        }
        if(n==2)
        {
            return x*x;
        }
        if(n==-2)
        {
            return 1/(x*x);
        }
        if(n==-1)
        {
            return 1/(x);
        }
        if(n%2==0)
        {
            return (myPow(x,n/2) * myPow(x,n/2));
        }
        else
        {
            double signn = n<0?1/x:x;
            return (myPow(x, n/2) * myPow(x, n/2) * signn);
        }
    }
};
