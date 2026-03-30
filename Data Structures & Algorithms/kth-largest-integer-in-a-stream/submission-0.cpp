class KthLargest {
public:
    int m_k;
    multiset<int> S;
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for (auto x: nums)
            S.insert(x);
    }
    
    int add(int val) {
        S.insert(val);
        auto it = S.rbegin();
        advance(it,m_k-1);
        return *it;
    }
};
