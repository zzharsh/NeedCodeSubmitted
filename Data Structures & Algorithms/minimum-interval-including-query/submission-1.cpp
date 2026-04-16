class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<vector<int>> Q(m, vector<int>(2,0));
        vector<int> res(m, -1);
        for(int i = 0; i < m; ++i)
        {
            Q[i][0] = queries[i];
            Q[i][1] = i;
        }
        sort(Q.begin(), Q.end(), [](vector<int> a, vector<int> b)
        {
            return a[0] < b[0];
        });
        sort(intervals.begin(), intervals.end(),[](vector<int> a, vector<int> b)
        {
            if(a[0] == b[0])
            {
                return a[1] < b[1];
            }
            else
            {
                return a[0] < b[0];
            }
        });
        // for(int i = 0; i < m; ++i)
        // {
        //     printf("%d, %d | ", Q[i][0], Q[i][1]);
        // }
        // cout<<endl;
        // for(int i = 0; i < n; ++i)
        // {
        //     printf("%d, %d | ", intervals[i][0], intervals[i][1]);
        // }
        multimap<int, vector<int>> minHeap;
        int j = 0;
        for (int i = 0; i < m; ++i)
        {
            while(!minHeap.empty() && (minHeap.begin()->second[1] < Q[i][0]))
            {
                auto it = minHeap.begin();
                printf("%d Pop %d, %d \n", Q[i][0], it->second[0], it->second[1]);
                minHeap.erase(it);
            }
            while(j < n && intervals[j][0] <= Q[i][0])
            {
                if(intervals[j][1] >= Q[i][0])
                {
                    printf("%d push %d, %d \n", Q[i][0], intervals[j][0], intervals[j][1]);
                    minHeap.insert(make_pair(intervals[j][1] - intervals[j][0] + 1, intervals[j]));
                }
                j++;
            }
            if(!minHeap.empty())
            {
                res[Q[i][1]] = minHeap.begin()->first;
            }
        }
        return res;
    }
};
