class Twitter {
public:
    vector<unordered_set<int>> followers;
    vector<map<int, int>> tweets;
    long recentness = 0;   
    Twitter() {
        followers.resize(101);
        tweets.resize(100);
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert(make_pair(recentness++, tweetId));
        followers[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        unordered_set<int> picked;
        cout<<" User: "<<userId<<" Picks: ";
        for(int j = 0; j < 10; ++j)
        {
            int tweet = -1;
            int recentness = -1;
            for(auto it = followers[userId].begin(); it!=followers[userId].end(); ++it)
            {
                if(tweets[*it].begin() != tweets[*it].end())
                {
                    auto it1 = tweets[*it].end();
                    it1--;
                    if(picked.find(it1->second) == picked.end())
                    {
                        if(recentness < it1->first && 
                            picked.find(it1->second) == picked.end())
                        {
                            recentness = it1->first;
                            tweet = it1->second;
                        }
                    }
                }
            }
            if(tweet == -1) break;
            picked.insert(tweet);
            ans.push_back(tweet);
            cout<<tweet<<" "<<recentness<<" : ";
        }
        cout<<"\n";
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
        followers[followerId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followers[followerId].erase(followeeId);
        }
    }
};
