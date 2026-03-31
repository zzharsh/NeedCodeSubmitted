class TimeMap {
public:
    struct timeMap{
        int    timestamp;
        string value;
        timeMap(int ts, string val) : timestamp(ts), value(val) {}
    };
    unordered_map<string, vector<timeMap>> kV; 
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        kV[key].push_back(timeMap(timestamp, value));
    }
    
    string binarySearch(vector<timeMap>& data, int target)
    {
        if(data.size() == 0)
        {
            return "";
        }
        else if(data.size() == 1)
        {
            if(data[0].timestamp <= target)
            {
                // cout<<data[0].value<<"\n";
                return data[0].value;
            }
            else
            {
                return "";
            }
        }
        int s = 0, e = data.size()-1;
        while(s <= e)
        {
            int m = (s+e) / 2;
            if(data[m].timestamp == target)
            {
                return data[m].value;
            }
            if(data[m].timestamp > target)
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        if(data[e].timestamp > target && e-1 >= 0)
        {
            return data[e-1].value;
        }
        else
        {
            return data[e].value;
        }
    }

    string get(string key, int timestamp) {
        cout<<key<<" "<<kV[key].size()<<"\n";
        return binarySearch(kV[key], timestamp);
    }
};
