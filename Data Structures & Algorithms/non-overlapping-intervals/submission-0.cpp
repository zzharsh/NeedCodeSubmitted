struct CustomCompare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        // Sort by name in ascending order
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        // If names are the same, sort by ID in descending order
        return a[1] < b[1];
    }
};

class Solution {
public:
    bool isOverlap(const vector<int>& i1, const vector<int>& i2)
    {
        if(i1[1] > i2[0])
        {
            return true;
        }
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        multiset<vector<int>, CustomCompare> S;
        int n = intervals.size();
        for(int i = 0; i < n; ++i)
        {
            S.insert(intervals[i]);
        }
        auto it = S.begin();
        while(it != S.end())
        {
            auto it1 = it;
            it1++;
            if(it1 == S.end()) break;
            cout<<(*it)[0]<<" "<<(*it)[1]<<" "<<
                (*it1)[0]<<" "<<(*it1)[1]<<"\n";
            if( isOverlap(*it, *it1))
            {
                vector<int> i1 = *it, i2 = *it1;
                cout<<"Overlap detected"<<(*it)[0]<<" "<<(*it)[1]<<" "<<
                (*it1)[0]<<" "<<(*it1)[1]<<"\n";
                if(i1[1]-i1[0] < i2[1]-i2[0])
                {
                    S.erase(it1);
                    // it = it1;
                }
                else
                {
                    S.erase(it);
                    it = it1;
                }
                
            }
            else
            {
                it++;
            }
        }
        return n - S.size();
    }
};
