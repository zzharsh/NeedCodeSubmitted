class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0, n = cost.size();
        int sG = 0, sC = 0, minDiff = 10000, iDiff = -1;
        for(i = 0; i < n; ++i)
        {
            sG += gas[i];
            sC += cost[i];
        }
        if(sG < sC) return -1;
        int ans = i;
        for(i = 0; i < n; ++i)
        {
            int j = (i+1) % n;
            int currDiff = gas[i] - cost[i];
            int nextDiff = gas[j] - cost[j];
            cout<<i<<" "<<currDiff<<" "<<nextDiff<<"\n";
            if(currDiff > 0 && currDiff > abs(nextDiff)) 
            {
                cout<<"Return"<<"\n";
                return i;
            }
        }
        return ans;
    }
};
