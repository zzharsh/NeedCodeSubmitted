class Solution {
public:
    vector<int> values;
    int findSmall()
    {
        int n = values.size();
        int s = 0;
        int e = values.size()-1;
        int m = (s+e) / 2;
        // while(s >= 0 && e < n)
        int loopeda = n;
        while(loopeda-- > 0)
        {
            m = (s+e) / 2;
            int l = (m-1) > 0 ? m-1 : n-1;
            int r = (m+1) < n ? m+1 : 0;
            // cout<<m<<" "<<values[m]<<" "<<values[l]<<" "<<values[r]<<"\n";
            if(values[m] < values[r] && values[m] < values[l])
            {

                // cout<<" returning ";
                return m;
            }
            if(values[m] > values[e])
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        } 
        return 0;
    }
    int search(vector<int>& nums, int target) {
        values = move(nums);
        // int n = values.size();
        int offset = findSmall();
        int ans = -1;
        int s = offset, e = (values.size()-1 + offset), n = values.size();
        int m = ((s + e)%n)/2;
        int loopeda = n;
        while(s < e)
        // while(loopeda-- > 0)
        {
            m = (s + e)/2;
            int im = m % n;
            cout<<s<<" "<<e<<" "<<" ";
            cout<<m<<" "<<values[im]<<"\n";
            if(values[im] == target)
            {
                return im;
            }
            if(values[im] > target)
            {
                e = m-1;
            }
            else
            {
                s = m+1;
            }
        }
        return -1;
        return offset;
    }
};
