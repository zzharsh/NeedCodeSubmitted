class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> S;
        for(auto x:stones)
        {
            S.insert(x);
        }
        while(S.size()>1)
        {
            auto it = S.end();
            it--;
            int b1 = *it;
            S.erase(it);

            it = S.end();
            it--;
            int b2 = *it;
            S.erase(it);
            if(b1 > b2)
            {
                S.insert(b1-b2);
            }
        }
        if(S.empty())
        {
            return 0;
        }
        else
        {
            auto it = S.end();
            it--;
            return *it;
        }
    }
};
