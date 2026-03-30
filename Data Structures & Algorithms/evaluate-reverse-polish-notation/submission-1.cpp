class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        int i = 0, n = tokens.size();
        for(i=0;i<n;++i)
        {
            if ((tokens[i] == "+") || (tokens[i] == "-") || (tokens[i] == "*") || (tokens[i] == "/"))
            {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                if (tokens[i] == "+")
                {
                    S.push(a + b);
                }
                if (tokens[i] == "-")
                {
                    S.push(b-a);
                }
                if (tokens[i] == "*")
                {
                    S.push(a * b);
                }
                if (tokens[i] == "/")
                {
                    S.push(b/a);
                }
                cout<<a<<" "<<b<<" "<<S.top()<<"\n";
            }
            else
            {
                S.push(stoi(tokens[i]));
            }
        }
        return S.top();
        
    }
};
