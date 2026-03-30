class Solution {
public:
    bool isValid(const vector<int>& tMap, vector<int>& sMap)
    {
        // cout<<endl;
        for(int i = 0; i < tMap.size(); ++i)
        {
            // if(sMap[i] > 0 || tMap[i] > 0 )
            // {
            //     cout<<"cmp "<<i<<" "<<sMap[i]<<" "<<tMap[i]<<endl;
            // }
            if(sMap[i] < tMap[i])
            {
                return false;
            }
        }
        return true;
    }
    int hash(char ch)
    {
        if(ch >= 'a')
        {
            return ((ch - 'a') + 30);
        }
        else
        {
            return (ch - 'A');
        }
    }
    string minWindow(string s, string t) {
        int minLen = 10000;
        string res = "";
        int resi, resj;
        vector<int> tMap(60, 0), sMap(60,0);
        int i = 0, j = 0, n = s.size(), m = t.size();
        for(i = 0; i < m; ++i)
        {
            tMap[hash(t[i])]++;
        }
        i = 0;
        while(i < n && j < n)
        {
            while((j < n) && (false == isValid(tMap, sMap)))
            {
                sMap[hash(s[j++])]++;
                // j += 1;
            }
            // --j;
            if (isValid(tMap, sMap) && (j - i < minLen))
            {
                resi = i;
                resj = j;
                minLen = j - i;
            }
            cout<<i<<" "<<j<<" "<<isValid(tMap, sMap)<<" "<<minLen<<"\n";
            while(i < n)
            {
                sMap[hash(s[i++])]--;
                cout<<"increasei "<<i<<" "<<j<<" "<<isValid(tMap, sMap)<<" "<<minLen<<"\n";
                if(isValid(tMap, sMap))
                {
                    if (j - i < minLen)
                    {
                        resi = i;
                        resj = j;
                        minLen = j - i;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if(minLen == 10000)
        {
            return res;
        }
        // for(int i = resi; i <=resj; ++i)
        // {
        //     res ;
        // }
        res = s.substr(resi, resj - resi);
        return res;
    }
};
