#include <iostream>
#include <vector>
#include <tuple>
#include <dequeue>
#include <priority_queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Twitter {
    const int MaxFeed = 10;
    unordered_map<int, deque<pair<int, int>>> userPosts;
    unordered_map<int, unordered_set<int>> userFollows;
    int timeStamp = 0;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto& posts = userPosts[userId];
        // Do not use it in multi-threading.
        posts.emplace_front(pair<int, int>(timeStamp++, tweetId));
        while (posts.size() > MaxFeed)
            posts.pop_back();
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        auto follows = userFollows[userId];
        follows.insert(userId);
        priority_queue<tuple<int, int, int, int>> heap;
        for (auto id : follows) {
            const auto& post = userPosts[id];
            if (post.empty())
                continue;
            heap.push(make_tuple(post[0].first, post[0].second, id, 0));
        }
        while (feed.size() < MaxFeed && !heap.empty()) {
            auto curr = heap.top();
            heap.pop();
            feed.push_back(get<1>(curr));
            auto index = get<3>(curr) + 1;
            auto id = get<2>(curr);
            const auto& post = userPosts[id];
            if (post.size() > index)
                heap.push(make_tuple(post[index].first, post[index].second, id, index));
        }
        return feed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        userFollows[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto& follows = userFollows[followerId];
        auto it = follows.find(followeeId);
        if (it != follows.end())
            follows.erase(it);
    }
};

int main(void) {
    return 0;
}
