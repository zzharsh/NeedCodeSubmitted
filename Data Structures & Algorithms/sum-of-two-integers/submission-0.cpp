class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int z = 0;
        int ans = 0;
        while(z<32)
        {
            int ab = ( a & 1<<z);
            int bb = (b & 1<<z), cb = (c<<z);
            ans = ans | ((ab ^ bb) ^ (cb));
            c = ((ab & bb) | (ab & cb) | (bb & cb)) ? 1 : 0;
            // cout<<ans<<" "<<c<<" "<<(1<<z)<<" "<<( a & 1<<z)<<" "<<(b & 1<<z)<<"\n";
            z++;
        }
        return ans;
    }
};
