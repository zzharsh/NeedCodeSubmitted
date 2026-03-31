class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> DeleteDP(n, 0);
        int res = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
            {
                if(a[0] == b[0])
                {
                    return a[1] < b[1];
                }
                return a[0] < b[0];
            }
            );
        int s = 0, e = 0;
        while(s < n && e < n)
        {
            if(s == e)
            {
                if(e+1 < n)
                {
                    e++;
                }
                else
                {
                    break;
                }
            }
            printf("s=%d, e=%d, e[0]=%d, s[1]=%d\n", s, e, intervals[e][0], intervals[s][1]);
            if(intervals[e][0] < intervals[s][1])
            {
                DeleteDP[e]++;
                DeleteDP[s]++;
                if(intervals[e][1] > intervals[s][1])
                {
                    s++;
                }
                else
                {
                    e++;
                }
            }
            else
            {
                s++;
                e++;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            printf("[%d,%d]:%d, ", intervals[i][0], intervals[i][1], DeleteDP[i]);
        }
        s = 0; e = 0;
        while(s < n && e < n)
        {
            if(s == e)
            {
                if(e+1 < n)
                {
                    e++;
                }
                else
                {
                    break;
                }
            }
            if(intervals[e][0] < intervals[s][1])
            {
                res++;
                if(DeleteDP[s] > DeleteDP[e])
                {
                    s=e;
                }
                else
                {
                    e++;
                }
            }
            else
            {
                s++;
                e++;
            }
        }
        return res;

    }
};
