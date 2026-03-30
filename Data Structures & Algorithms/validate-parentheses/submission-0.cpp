class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool res = false;
        unordered_set<char> open = {'{','(','['};
        unordered_map<char, char> openclose;
        openclose['{'] = '}';
        openclose['['] = ']';
        openclose['('] = ')';
        // cout<<s.size()<<" "<<s.length();
        for (int i=0;i<s.size();++i)
        {
            // if(st.size()!=0)
            // {
            //     cout<<st.top()<<" "<<i<<" "<<s[i]<<" "<<openclose[s[i]]<<"\n";
            // }
            if(open.end() != open.find(s[i]))
            {
                st.push(s[i]);
            }
            else
            {
                if(st.size() == 0)
                {
                    res = false;
                    return res;
                }
                else if (openclose[st.top()] == s[i])
                {
                    // cout<<" popping "<<" "<<s[i]<<"\n";
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.size()==0)
        {
            return true;
        }
        return false;
    }
};
