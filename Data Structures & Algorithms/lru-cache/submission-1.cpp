class LRUCache {
private: 
    map<int, int> PQ;
    unordered_map<int, vector<int>> MP;
    int m_Capacity = 0;
    int recent_access = 0;
    int current_Capacity = 0;
public:
    LRUCache(int capacity) {
        m_Capacity = capacity;
        recent_access = 0;
        current_Capacity = 0;        
    }
    
    int get(int key) {
        if(MP.find(key) == MP.end())
        {
            return -1;
        }
        else
        {
            int ra = MP[key][1];
            PQ.erase(ra);
            PQ[++recent_access] = key;
            MP[key] = {MP[key][0], recent_access};
            return MP[key][0];
        }
    }
    
    void put(int key, int value) {
        cout<<current_Capacity<<" "<<m_Capacity<<" "<<PQ.size()<<" "<<MP.size()<<" "<<key<<"\n";
        if(MP.find(key) != MP.end())
        {
            int ra = MP[key][1];
            PQ.erase(ra);
            PQ[++recent_access] = key;
            MP[key] = {value, recent_access};
        }
        else
        {
            if(current_Capacity == m_Capacity)
            {
                // cout<<" FullCapacity ";
                int remove_key = PQ.begin()->second;
                PQ.erase(PQ.begin()->first);
                MP.erase(remove_key);
                ++recent_access;
                MP[key] = {value, recent_access};
                PQ[recent_access] = key;
            }
            else
            {
                ++recent_access;
                MP[key] = {value, recent_access};
                PQ[recent_access]=key;
                current_Capacity++;
            }
        }
    }
};
