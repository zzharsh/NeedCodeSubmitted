
struct Compare {
    bool operator()(const vector<int>& A,const vector<int>& B)
    {
        return A[0] > B[0];
    }
};
class LRUCache {
private: 
    priority_queue<vector<int>, vector<vector<int>>, Compare> PQ;
    unordered_map<int, int> MP;
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
            return MP[key];
        }
    }
    
    void put(int key, int value) {
        if(current_Capacity == m_Capacity)
        {
            int remove_key =  PQ.top()[1];
            PQ.pop();
            MP.erase(remove_key);
            MP[key] = value;
            PQ.push({++recent_access, key});
        }
        else
        {
            MP[key] = value;
            PQ.push({++recent_access, key});
            current_Capacity++;
        }
    }
};
