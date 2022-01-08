#include <bits/stdc++.h>
using namespace std;
class Twitter
{
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int time;
    Twitter()
    {
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> feeds;
        vector<pair<int, int>> temp;
        for (auto it : tweets[userId])
            temp.push_back(it);
        for (auto it : follows[userId])
        {
            for (auto i : tweets[it])
                temp.push_back(i);
        }
        sort(temp.begin(), temp.end(), greater<pair<int, int>>());
        for (int i = 0; i < 10 && i < temp.size(); i++)
            feeds.push_back(temp[i].second);
        return feeds;
    }

    void follow(int followerId, int followeeId)
    {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].erase(followeeId);
    }
};

int main()
{
    return 0;
}