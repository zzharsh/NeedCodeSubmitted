class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), ans = 0;
        while(r < n-1)
        {
            int t = r;
            cout<<"l: "<<l<<" "<<"r: "<<r<<" ";
            for(int k = l; k < t+1; ++k)
            {
                if(k<n)
                    r = max(k+nums[k], r);
                else break;
                cout<<r<<" ";
            }
            cout<<"\n";
            l = t+1;
            // r = t;
            ans++;
        }
        return ans;
        
    }
};
