class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i=0, j=0;
        while(i+j<s3.size())
        {
            if((s3[i+j] == s1[i]) && (s3[i+j] == s2[j]))
            {
                if((isInterleave(s1.substr(i+1), s2.substr(j), s3.substr(i+j+1)) == true) ||
                   ((isInterleave(s1.substr(i), s2.substr(j+1), s3.substr(i+j+1)) == true)))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if(s3[i+j] == s1[i])
            {
                ++i;
            }
            else if(s3[i+j] == s2[j])
            {
                ++j;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
