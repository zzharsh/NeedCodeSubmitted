class Solution {
public:
    void *memcpy(void *dest, const void *src, size_t n)
    {
        size_t i;

        for (i = 0; i < n; ++i)
            ((unsigned char *) dest)[i] = ((unsigned char *) src)[i];

        return dest;
    }
    int reverse(int x) {
        int maxDigits[10], minDigits[10];
        cout<<INT_MAX<<" "<<INT_MIN<<" ";
        int a = x, i;
        int xDigs = 0;
        while(a!=0)
        {
            a /= 10;
            xDigs++;
        }
        a = INT_MAX;
        i = 0;
        int ans = 0;
        while(a!=0)
        {
            maxDigits[i++] = a % 10;
            a = a / 10;
        }
        memcpy(&minDigits, &maxDigits, sizeof(maxDigits));
        minDigits[0]++;
        for(i = 0; i < 10; ++i)
        {
            cout<<maxDigits[i];
        }
        cout<<"\n";
        for(i = 0; i < 10; ++i)
        {
            cout<<minDigits[i];
        }
        int* comp;
        if(x < 0)
        {
            comp = minDigits;
        }
        else
        {
            comp = maxDigits;
        }
        cout<<"\n";
        i = 0;
        while(x!=0)
        { 
            a = x%10;
            if(xDigs == 10 && a > comp[i++])
            {
                return 0;
            }
            ans = ans * 10 + a;
            cout<<a<<" ";
            x /= 10;
        }
        return ans;
    }
};
