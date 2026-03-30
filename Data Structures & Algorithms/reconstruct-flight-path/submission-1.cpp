bool comp(vector<string> s1, vector<string> s2)
{
    if(s1[0] == s2[0])
    {
        return s1[1] < s2[1];
    }
    else
    {
        return s1[0] < s2[1];
    }
}
class Solution {
public:
    int k = 0;
    unordered_map<string, multiset<string>> adjList; 
    vector<string> res;
    bool DFS(string node)
    {
        k--;
        printf("[k = %d, Visiting, %s ->], ",k, node.c_str());
        res.push_back(node);
        if(k <= 0)
        {
            return true;
        }
        auto it = adjList[node].begin();
        while(it != adjList[node].end())
        {
            string backup = (*it);
            auto eraseIt = it;
            it++;
            adjList[node].erase(eraseIt);
            if(true == DFS(backup) && k <= 0)
            {
                return true;
            }
            adjList[node].insert(backup);
        }
        if(k==0) return true;
        k++;
        res.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // sort(tickets.begin(), tickets.end(), comp);
        k = tickets.size()+1;
        for(int i = 0; i < tickets.size(); ++i)
        {
            adjList[tickets[i][0]].insert(tickets[i][1]);
        }
        // for(auto it = adjList.begin(); it != adjList.end(); ++it)
        // {
        //     printf("[%s: ", it->first.c_str());
        //     // , tickets[i][1].c_str());
        //     for(auto sit = it->second.begin(); sit != it->second.end(); ++sit)
        //     {
        //         printf("%s ", (*sit).c_str());
        //     }
        //     cout<<"]"<<endl;
        // }
        DFS("JFK");
        return res;
    }
};
