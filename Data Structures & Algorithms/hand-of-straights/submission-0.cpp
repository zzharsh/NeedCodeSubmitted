class Solution {
public:
    map<int, int> values;
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        int n = hand.size();
        // int i;
        for(int x:hand)
        {
            auto it = values.find(x);
            if(it == values.end())
            {
                values.insert(make_pair(x, 1));
            }
            else
            {
                it->second++;
            }
        }
        for(auto it = values.begin(); it!=values.end(); ++it)
        {
            cout<<it->first<<" "<<it->second<<"\n";
        }
        for(int j = 0; j < n; j+=groupSize)
        {
            auto it = values.begin();
            int val = it->first;
            it->second--;
            for(int i = 1; i < groupSize; ++i)
            {
                it++;
                if(it->first != val+1)
                {
                    return false;
                }
                else
                {
                    it->second--;
                }
                val++;
            }
            it = values.begin();
            for(int i = 0; i < groupSize; ++i)
            {
                if(it->second == 0)
                {
                    auto temp = it;
                    it++;
                    values.erase(temp);
                }
                else
                {
                    it++;
                }
            }
        }
        return true;
    }
};
