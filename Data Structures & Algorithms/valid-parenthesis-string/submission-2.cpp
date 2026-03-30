class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star, bracket;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == '(')
            {
                bracket.push(i);
            }
            else if(s[i] == ')')
            {
                if(bracket.size()==0 && star.size()==0)
                {
                    return false;
                }
                else if(bracket.size()==0)
                {
                    star.pop();
                }
                else
                {
                    bracket.pop();
                }
            }
            else
            {
                star.push(i);
            }
        }
        while((bracket.size()!=0))
        {
            if((star.size()!=0) && (star.top() > bracket.top()))
            {
                bracket.pop();
                star.pop();
            }
            else
            {
                break;
            }
        }
        if(bracket.size()!=0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
