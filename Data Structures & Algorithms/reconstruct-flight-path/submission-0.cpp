struct edge {
    string to_i;
    string from_i;
    edge(string a, string b) : from_i(a), to_i(b) {}
};
struct Lexo {
    using is_transparent = void;
    bool operator()(const edge& a, const edge& b) const
    {
        if(a.from_i == b.from_i)
        {
            return a.to_i < b.to_i;
        }
        else
        {
            return a.from_i < b.from_i;
        }
    }
    bool operator()(const string& a, const edge& b) const
    {
        return a < b.from_i;
    }
    bool operator()(const edge& a, const string& b) const
    {
        return a.from_i < b;
    }
    
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        multiset<edge, Lexo> edgeSet;
        int n = tickets.size();
        for(int i = 0; i < n; ++i)
        {
            edgeSet.emplace(edge(tickets[i][0], tickets[i][1]));
        }
        for(auto it = edgeSet.begin(); it != edgeSet.end(); ++it)
        {
            cout<<it->from_i<<" "<<it->to_i<<"\n";
        }
        string currentFrom = "JFK";
        vector<string> res;
        res.push_back(currentFrom);
        while(!edgeSet.empty())
        {
            auto it = edgeSet.find(currentFrom);
            res.push_back(it->to_i);
            currentFrom = it->to_i;
            edgeSet.erase(it);
        }
        return res;
    }
};
