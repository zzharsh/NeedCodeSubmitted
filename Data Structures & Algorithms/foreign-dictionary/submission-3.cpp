class Solution {
public:
    std::vector<std::unordered_set<char>> Lists = vector<unordered_set<char>>(26);
    std::vector<bool> visited = vector<bool>(26, false);
    bool cycle = false;
    string DFS(char ch, unordered_set<char> current)
    {
        printf("called %c %d\n ", ch + 'a', ch);
        if(visited[ch] == true)
        {
            return "";
        }
        if(current.find(ch) != current.end(ch))
        {
            cycle = true;
            return "";
        }
        if(cycle == true)
        {
            return "";
        }
        current.insert(ch);
        string str = "";
        for(auto it = Lists[ch].begin(); it != Lists[ch].end(); ++it)
        {
            str = DFS(*(it), current);
        }
        visited[ch] = true;
        printf("visiting %c \n ", ch + 'a');
        return str + static_cast<char>(ch + 'a');
    }
    string foreignDictionary(vector<string>& words) {
        // char first = " ";
        int n = words.size();
        vector<bool> exists(26, 0);
        char first = words[0][0];
        for(int i = 0; i < n-1; ++i)
        {
            int j = 0;
            while(j < words[i].size() && j < words[i+1].size() && words[i][j] == words[i+1][j])
            {
                exists[words[i][j] - 'a'] = true;
                exists[words[i+1][j] - 'a'] = true;
                j++;
            }
            if (j < words[i].size() && j < words[i+1].size())
            {
                exists[words[i][j] - 'a'] = true;
                exists[words[i+1][j] - 'a'] = true;
                Lists[words[i+1][j] - 'a'].insert(words[i][j] - 'a');
            }
            else if(words[i].size() > words[i+1].size())
            {
                return "";
            }
            while (j < words[i].size() && j < words[i+1].size())
            {
                exists[words[i][j] - 'a'] = true;
                exists[words[i+1][j] - 'a'] = true;
                ++j;
            }
            while(j < words[i].size())
            {
                exists[words[i][j] - 'a'] = true;
                ++j;
            }
            while(j < words[i+1].size())
            {
                exists[words[i+1][j] - 'a'] = true;
                ++j;
            }
        }
        for (int i = 0 ; i < 26; ++i)
        {
            printf("%c, %d ", i + 'a', static_cast<int>(exists[i]));
            for(auto it = Lists[i].begin(); it != Lists[i].end(); ++it)
            {
                printf(": %c", ((*it) + 'a'));
            }
            // for(int j = 0; j < Lists[i].size();++j)
            // {
            //     printf(": %c", (Lists[i][j] + 'a'));
            // }
            cout<<endl;
        }
        string res = "";
        for(int i = 0; i < 26; ++i)
        {
            if(exists[i] == true && false == visited[i])
            {
                printf("calling %c %d \n ", i + 'a', i);
                res = res + DFS(static_cast<char>(i), unordered_set<char>());
            }
        }
        if(true == cycle)
        {
            return "";
        }
        return res;

    }
};
