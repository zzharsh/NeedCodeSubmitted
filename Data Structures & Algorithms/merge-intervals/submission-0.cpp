class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        int i = 0, n = intervals.size();
        for(i=0;i<n-1;++i)
        {
            if(intervals[i][1] >= intervals[i+1][0])
            {
                cout<<"Merging: "<<(intervals[i][1] >= intervals[i+1][0])<<" "<<
                intervals[i][0]<<" "<<intervals[i][1]<<" | "<<
                intervals[i+1][0]<<" "<<intervals[i+1][1]<<"\n";
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
                intervals.erase(intervals.begin() + i+1);
                i--;
                n--;
            }

        }
        return intervals;
    }
};
