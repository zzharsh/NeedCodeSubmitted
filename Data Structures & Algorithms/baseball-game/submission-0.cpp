class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> records;
        for(string s:operations)
        {
            if(s == "+")
            {
                int top = records.top();
                records.pop();
                int addRes = records.top() + top;
                records.push(top);
                records.push(addRes);
            }
            else if(s=="D")
            {
                records.push(records.top()*2);
            }
            else if(s=="C")
            {
                records.pop();
            }
            else
            {
                int rec = stoi(s);
                records.push(rec);
            }
        }
        int res = 0;
        while(!records.empty())
        {
            res += records.top();
            records.pop();
        }
        return res;
    }
};