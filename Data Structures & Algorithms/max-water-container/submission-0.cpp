class Solution {
public:
    int maxArea(vector<int>& heights) {
        stack<int> left, right;
        int l, r, n = heights.size();
        l = 0;
        r = n-1;
        int ans = 0;
        left.push(heights[l]);
        right.push(heights[r]);
        while(r > l)
        {
            cout<<ans<<" "<<((r - l) * min(left.top(), right.top()))<<" ";
            if(((r - l) * min(left.top(), right.top())) > ans)
            {
                // cout<<ans<<" ";
                ans = (r - l) * min(left.top(), right.top());
            }
            if(heights[r] < heights[l])
            {
                r--;
                cout<<"r-- "<<r<<"\n";
                right.push(heights[r]);
            }
            else
            {
                l++;
                cout<<"l++ "<<l<<"\n";
                left.push(heights[l]);
            }
        }
        return ans;
    }
};
