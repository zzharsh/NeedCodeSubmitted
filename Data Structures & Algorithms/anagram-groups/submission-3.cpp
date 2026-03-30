class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> alpcount;
        vector<vector<string>> result;
        for(int i=0;i<strs.size();++i)
        {
            vector<int> scount(26,0);
            for(int j=0;j<strs[i].size();++j)
            {
                scount[strs[i][j] - 'a']++;
            }
            string sstr="";
            for(int j=0;j<26;++j)
            {
                sstr = sstr+ ","+ to_string(scount[j]);
            }
            alpcount[sstr].push_back(strs[i]);
        }
        for(auto itr:alpcount)
        {
            // cout<<itr.first;
            result.push_back(itr.second);
        }
        return result;
        }
    };
