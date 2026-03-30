class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<vector<int>> st;
        int i=0, n = temperatures.size();
        vector<int> res(n, 0);
        for(i=n-1;i>=0;--i)
        {
            if(st.size() == 0)
            {
                st.push(vector<int>({temperatures[i],i}));
                res[i] = 0;
            }
            else
            {
                while ((st.size()>0) && (temperatures[i] >= st.top()[0]))
                {
                    cout<<"Popping "<<st.top()[0]<<" ";
                    st.pop();
                }
                if(st.size()==0)
                {
                    res[i] = 0;
                    st.push(vector<int>({temperatures[i],i}));
                }
                else
                {
                    res[i] = st.top()[1] - i;
                    st.push(vector<int>({temperatures[i],i}));
                }
            }
            cout<<res[i]<<" "<<temperatures[i]<<" ";
        }
        return res;
    }
};
