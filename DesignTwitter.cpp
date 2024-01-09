class Twitter {
public:
    unordered_map<int, unordered_set<int>> i_follow;
    unordered_map<int,int> tweet_user;
    vector<int> global_tweet_ordering;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet_user[tweetId] = userId;
        global_tweet_ordering.insert(global_tweet_ordering.begin(), tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for(int i = 0;i<global_tweet_ordering.size() && res.size()<10;i++)
        {
            int tweet = global_tweet_ordering[i];
            if(tweet_user[tweet]==userId || i_follow[userId].find(tweet_user[tweet])!=i_follow[userId].end())
            {
                res.push_back(tweet);
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        i_follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        i_follow[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
