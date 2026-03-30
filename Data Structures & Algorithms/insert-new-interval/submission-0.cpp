class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int it = 0;
        for(; it < n; ++it)
        {        
            // cout<<it<<" ";  
            if(newInterval[0] < intervals[it][0])
            {
                break;
            }
        }
        intervals.insert(intervals.begin() + it, newInterval);
        n++;
        for(it=0;it<n-1;++it)
        {
            cout<<it<<" "<<intervals.size()<<" "<<n<<" | ";
            if(intervals[it+1][0] <= intervals[it][1])
            {
                intervals[it][1] = max(intervals[it][1], intervals[it+1][1]);
                intervals.erase(intervals.begin() + it+1);
                it--;
                n--;
                cout<<"Merged "<<it+1<<" "<<it+2<<"\n";
            }
        }
        return intervals;
    }
};
