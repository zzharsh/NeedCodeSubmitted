class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0, multiplier = 31;
        while(n>0)
        {
            cout<<n<<" "<<(n & 1 > 0) <<" "<<(multiplier)<<" \n";
            ans += n & 1 > 0 ? pow(2,multiplier) : 0;
            multiplier--;
            n = n >> 1;
        }
        return ans;

    }
};
