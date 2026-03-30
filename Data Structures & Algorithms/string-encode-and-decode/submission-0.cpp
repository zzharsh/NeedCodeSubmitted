class Solution {
public:
    unordered_map<int, int> stccnt;
    int len = 0;
    string encode(vector<string>& strs) {
        string result="";
        len = strs.size();
        for(int i=0;i<strs.size();++i)
        {
            result =result+strs[i];
            stccnt[i] = strs[i].size();
        }
        return result;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int j=0;
        for(int i=0;i<len;++i)
        {
            string str = "";
            
            for(int k = j; k<stccnt[i]+j;++k)
            {
                str = str + s[k];
            }
            j += str.size();
            result.push_back(str);
        }
        return result;

    }
};
