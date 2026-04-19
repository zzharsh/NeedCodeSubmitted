class Solution {
public:
    vector<vector<pair<int, int>>> adjList;
    vector<int> finalTime;
    vector<bool> visited;
    void Bellmond(int i, int time)
    {
        printf("called = %d %d %d %d\n", i, time, static_cast<int>(visited[i]), finalTime[i]);
        if(finalTime[i] <= time)
        {
            return;
        }
        visited[i] = true;
        finalTime[i] = time;
        for(int j = 0; j < adjList[i].size(); ++j)
        {
            Bellmond(adjList[i][j].first, adjList[i][j].second + time);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        adjList = std::move(vector<vector<pair<int, int>>>(n+1));
        visited = std::move(vector<bool>(n+1));
        finalTime = std::move(vector<int>(n+1, INT_MAX));
        for(int i = 0; i < times.size(); ++i)
        {
            int s = times[i][0];
            int e = times[i][1];
            int t = times[i][2];
            adjList[s].push_back(make_pair(e, t));
        }
        Bellmond(k, 0);
        int res = -1;
        for(int i = 1; i < n +1; ++i)
        {
            if(visited[i] == false)
            {
                return -1;
            }
            res = max(res, finalTime[i]);

        }
        return res;
    }
};
