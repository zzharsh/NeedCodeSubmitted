class MyHashSet {
public:
    int size;
    int bucketSize;
    vector<vector<int>> keys;
    MyHashSet() {
        size = 0;
        bucketSize = 2048;
        keys = std::move(vector<vector<int>>(bucketSize));
    }
    
    int hash(int key)
    {
        return (key % bucketSize);
    }

    void add(int key) {
        if(true == contains(key))
        {
            return;
        }
        size++;
        if(size * 2 > bucketSize)
        {
            vector<vector<int>> newKeys(bucketSize * 2);
            for(int i = 0; i < bucketSize; ++i)
            {
                for(int x:keys[i])
                {
                    newKeys[hash(x)].push_back(x);
                }
            }
            keys = std::move(newKeys);
            bucketSize *= 2;
        }
        keys[hash(key)].push_back(key);
    }
    
    void remove(int key) {
        if(false == contains(key))
        {
            return;
        }
        vector<int>& hashes = keys[hash(key)];
        for(auto i=hashes.begin(); i != hashes.end(); ++i)
        {
            if(*(i) == key)
            {
                hashes.erase(i);
                break;
            }
        }
    }
    
    bool contains(int key) {
        for(int x: keys[hash(key)])
        {
            if(x==key)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */