class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0, n = cost.size();
        int sG = 0, sC = 0, minDiff = 10000, iDiff = -1;
        for(i = 0; i < n; ++i)
        {
            sG += gas[i];
            sC += cost[i];
            if(gas[i] - cost[i] < minDiff)
            {
                minDiff = gas[i] - cost[i];
                iDiff = i;
            } 
            cout<<minDiff<<" "<<iDiff<<" ";
        }
        if(sG < sC) return -1;
        int ans = (iDiff+1) % n;
        int maxAns = -1;
        for(i = 0; i < n; ++i)
        {
            if(gas[i] - cost[i] == minDiff)
            {
                int j = ( i+1 )% n;
                if(maxAns < gas[j] - cost[j])
                {
                    maxAns = gas[j] - cost[j];
                    ans = j;
                }
            }
        }
        return ans;
    }
};
