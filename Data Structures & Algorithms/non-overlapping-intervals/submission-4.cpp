class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
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
        int prev_end = intervals[0][1]; 
        for (int i = 1; i < n; ++i)
        {
            printf("prev_end: %d, int[%d]: [%d, %d]\n", prev_end, i, intervals[i][0], intervals[i][1]);
            if(intervals[i][0] < prev_end)
            {
                res++;
                prev_end = min(prev_end, intervals[i][1]);
            }
            else
            {
                prev_end = intervals[i][1];
            }
        }
        return res;
    }
};
