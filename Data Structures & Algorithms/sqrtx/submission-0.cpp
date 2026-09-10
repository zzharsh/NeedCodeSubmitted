class Solution {
public:
    int closest(int x, int m)
    {
        int dm = abs(x-m * m);
        int dm1 = abs(x-(m+1) * (m+1));
        int dm2 = abs(x-(m-1) * (m-1));
        if(dm < dm1 && dm < dm2)
        {
            return m;
        }
        else if(dm1 < dm && dm1 < dm2)
        {
            return m+1;
        }
        else
        {
            return m-1;
        }
    }
    int mySqrt(int x) {
        if(x==0 || x == 1) return x;
        // if(x==2) return 1;
        int s = 1, e = (x+1)/2, m = e;
        while(s < e && e*e >= x && s*s <= x)
        {
            m = (s+e)/2;
            printf("Exploring %d\n", m);
            if(m * m == x)
            {
                return m;
            }
            else if(m * m < x)
            {
                s = m+1;
            }
            else
            {
                e = m-1;
            }
        }
        if( m * m > x)
        {
            return m-1;
        }
        return m;
        // return closest(x,m);
    }
};