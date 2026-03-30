class Solution {
public:
    vector<vector<string>> keyPad = {
        {},
        {},
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}
    };
    vector<string> res;
    string D;
    int n;
    void iterate(int i, string running)
    {
        if(i >= n)
        {
            res.push_back(running);
            return;
        }
        int key = D[i] - '0';
        for(int j = 0; j < keyPad[key].size(); ++j)
        {
            iterate(i + 1, running + keyPad[key][j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        D = move(digits);
        n = D.size();
        iterate(0, "");
        return res;
    }
};
