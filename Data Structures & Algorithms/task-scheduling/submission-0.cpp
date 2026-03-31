class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mFreq;
        vector<int> sFreq;
        int sz = tasks.size();
        for(auto x: tasks)
        {
            mFreq[x]++;
        }
        for(auto it = mFreq.begin(); it!=mFreq.end(); ++it)
        {
            sFreq.push_back(it->second);
        }
        sort(sFreq.begin(), sFreq.end(), greater<int>());
        int ans = 0;
        while(sFreq[0] > 0)
        {
            int i = 0;
            int cycle = 0;
            while(i<sz && sFreq[i] > 0)
            {
                cout<<i<<" "<<sFreq[i]<<" "<<cycle<<"\n";
                sFreq[i++]--;
                cycle++;
            }
            while(cycle <= n) cycle++;
            ans += cycle;
        }
        return ans;
    }
};
