class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> freq;
        int n = hand.size();
        if(n%groupSize != 0) return false;
        for(int x:hand)
        {
            freq[x]++;
        }
        while(!freq.empty() && freq.begin()->second > 0)
        {
            int res = 1;
            auto it = freq.begin();
            it->second--;
            int curr = it->first;
            while(freq.find(curr-1) != freq.end() &&
                freq.find(curr-1)->second > 0 &&
                res < groupSize)
            {
                freq.find(curr-1)->second--;
                curr--;
                res++;
                cout<<res<<" "<<curr<<"\n";
            }
            curr = it->first;
            while(res < groupSize &&
                freq.find(curr+1) != freq.end() &&
                freq.find(curr+1)->second > 0)
            {
                freq.find(curr+1)->second--;
                curr++;
                res++;
                cout<<res<<" "<<curr<<"\n";
            }
            if(res < groupSize) return false;
            while(!freq.empty() && freq.begin()->second <= 0)
            {
                freq.erase(freq.begin()->first);
            }
        }
        return true;
    }
};
