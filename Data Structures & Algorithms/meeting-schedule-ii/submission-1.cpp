/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
                if(a.start == b.start)
                {
                    return a.end < b.end;
                }
                else
                {
                    return a.start < b.start;
                } 
            });
        int n = intervals.size(), i = 0;
        //  ans = 0;
        multiset<int> ends;
        for(i = 0; i < n; ++i)
        {
            // if(ends)
            cout<<intervals[i].start<<" "<<intervals[i].end<<" "<<ends.size()<<"\n";
            auto it = ends.lower_bound(intervals[i].start);
            // if(it != ends.end())
            // {
            //     cout<<"lowerBound "<<*it<<"\n";
            // }
            if(it == ends.end())
            {
                if(ends.size() > 0)
                {
                    it--;
                    if(*it <= intervals[i].start)
                    {
                        ends.erase(it);
                        ends.insert(intervals[i].end);
                    }
                    else
                    {
                        ends.insert(intervals[i].end);
                        // ans++;
                    }
                }
                else
                {
                    ends.insert(intervals[i].end);
                    // ans++;
                }
            }
            else if (*it == intervals[i].start)
            {
                ends.erase(it);
                ends.insert(intervals[i].end);
            }
            else
            {
                // if(*it < intervals[i].start)
                // {
                //     ends.erase(it);
                //     ends.insert(intervals[i].end);
                // }
                if(it!=ends.begin())
                {
                    it--;
                    ends.erase(it);
                    ends.insert(intervals[i].end);
                }
                else
                {
                    ends.insert(intervals[i].end);
                    // ans++;
                }
            }
            // if(it != ends.end())
            // {
            //     cout<<"mp "<<*it<<"\n";
            //     // if(*it)
            //     ends.erase(it);
            //     ends.insert(intervals[i].end);
            // }
            // else
            // {
            //     ends.insert(intervals[i].end);
            //     ans++;
            // }
            // auto it = upper_bound(intervals.begin(), intervals.end(), intervals[i].start,
            // [](Interval a, Interval b){
            //     return a.end < b.end;
            // });
            // cout<<(it==intervals.end() ? -1 : it->start)<<"\n";
        }
    
        return ends.size();
    }
};
