class Solution {
public:
    int climbStairs(int n) {
        if (n==1)
        {
            return 1;
        }
        int pre = 1, prepre = 1, ans = 0;
        for (int i=2;i<=n;++i)
        {
            ans = pre + prepre;
            prepre = pre;
            pre = ans;
        }
        return ans;
    }
};
