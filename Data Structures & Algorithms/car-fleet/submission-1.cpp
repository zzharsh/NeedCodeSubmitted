struct SP{
    int pos, sp;
    // float tm;
    SP(int p, int s) : pos(p), sp(s){}
    // SP{float f} : tm(f){}
    SP(){}
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int i, n = speed.size();
        vector<SP> sp(n);
        stack<float> fleet;
        int ans = 0;
        for(i = 0; i < n; ++i)
        {
            sp[i].pos = position[i];
            sp[i].sp  = speed[i];
        }
        sort(sp.begin(), sp.end(), [](SP A, SP B){return A.pos < B.pos;});
        for(i = n-1; i >= 0; --i)
        {
            float tm = ((target - sp[i].pos) * 1.0f) / sp[i].sp;
            cout<<sp[i].pos<<" "<<sp[i].sp<<" "<<tm<<"\n";
            if(fleet.size() == 0)
            {
                fleet.push(tm);
            }
            else
            {
                if(fleet.top() < tm)
                {
                    ans++;
                    cout<<"\n popping "<<fleet.top()<<" \n";
                    while(fleet.size() > 0)
                    {
                        fleet.pop();
                    }
                    fleet.push(tm);
                }
                // else
                // {
                //     fleet.push(tm);
                // }
            }
            
            
        }
        if (fleet.size() > 0)
        {
            ans++;
        }
        return ans;
    }
};
