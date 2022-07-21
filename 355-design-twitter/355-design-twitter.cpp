class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter()
    {
        
    }
    
    /** Compose a new tweet. */
    map<int,unordered_set<int>> followers;
    map<int,set<pair<int,int>>> feed;
    int count=0;
    void postTweet(int userId, int tweetId)
    {
        feed[userId].insert({count,tweetId});
        count--;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        int x=0;
        set<pair<int,int>> s;
        for(auto &tweet:feed[userId])
        {
            s.insert(tweet);
            x++;
            if(x==10)
                break;
        }
        for(auto &follower:followers[userId])
        {
            x=0;
            for(auto &tweet:feed[follower])
            {
                s.insert(tweet);
                x++;
                if(x==10)
                    break;
            }
        }
        for(auto tweet:s)
        {
            res.push_back(tweet.second);
            if(res.size()==10)
                break;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        followers[followerId].insert(followeeId);
    }
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        followers[followerId].erase(followeeId);
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