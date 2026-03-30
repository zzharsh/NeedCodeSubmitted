class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto t:tasks)
        {
            freq[t-'A']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        // [](int a, int b){return a>b;});
        int i = 0;
        int ans = 0;
        int it = 0;
        while(freq[0] > 0)
        {
            for(i = 0; i <= n; ++i)
            {
                bool flag = true;
                for(int j = 0; j < 26; ++j)
                {
                    if(flag && freq[j] == 0)
                    {
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag==true) return ans;
                if(i<26 && freq[i] > 0)
                {
                    freq[i]--;
                }
                ans++;
            }
            it++;
            cout<<"it: "<<it<<" ans: "<<ans<<"\n";
            sort(freq.begin(), freq.end(), greater<int>());
        }
        return ans;
    }
};
