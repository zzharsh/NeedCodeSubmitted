class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0, n = cost.size();
        int sG = 0, sC = 0, maxDiff = -1, iDiff = -1;
        for(i = 0; i < n; ++i)
        {
            sG += gas[i];
            sC += cost[i];
            if(gas[i] - cost[i] > maxDiff)
            {
                maxDiff = gas[i] - cost[i];
                iDiff = i;
            } 
        }
        if(sG < sC) return -1;
        return iDiff;
    }
};
