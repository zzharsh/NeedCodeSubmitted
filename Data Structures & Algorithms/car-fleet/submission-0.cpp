struct SP{
    int pos, sp;
    SP(int p, int s) : pos(p), sp(s){}
    SP(){}
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int i, n = speed.size();
        vector<SP> sp(n);
        for(i = 0; i < n; ++i)
        {
            sp[i].pos = position[i];
            sp[i].sp  = speed[i];
        }
        sort(sp.begin(), sp.end(), [](SP A, SP B){return A.pos < B.pos;});
        for(i = 0; i < n; ++i)
        {
            cout<<sp[i].pos<<" "<<sp[i].sp<<"\n";
        }
        return 0;
    }
};
