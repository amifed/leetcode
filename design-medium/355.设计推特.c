/*
 * @lc app=leetcode.cn id=355 lang=c
 *
 * [355] 设计推特
 *
 * https://leetcode-cn.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (36.70%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 15K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n' +
  '[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * 
 * 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
 * 
 * 
 * postTweet(userId, tweetId): 创建一条新的推文
 * getNewsFeed(userId):
 * 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
 * follow(followerId, followeeId): 关注一个用户
 * unfollow(followerId, followeeId): 取消关注一个用户
 * 
 * 
 * 示例:
 * 
 * 
 * Twitter twitter = new Twitter();
 * 
 * // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
 * twitter.postTweet(1, 5);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1关注了用户2.
 * twitter.follow(1, 2);
 * 
 * // 用户2发送了一个新推文 (推文id = 6).
 * twitter.postTweet(2, 6);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
 * // 推文id6应当在推文id5之前，因为它是在5之后发送的.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1取消关注了用户2.
 * twitter.unfollow(1, 2);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * // 因为用户1已经不再关注用户2.
 * twitter.getNewsFeed(1);
 * 
 * 
 */
#include <stdlib.h>
// @lc code=start
#define MAX_SIZE 1024

struct User {
  int id;                  //用户id
  int followee[MAX_SIZE];  //用户关注的用户id  (基于数组的散列)
  struct User* next;
};

struct Tweet {
  int userId;   //用户id
  int tweetId;  //推特id
  struct Tweet* next;
};

typedef struct {
  struct User* user;
  struct Tweet* tweet;
} Twitter;

/** Initialize your data structure here. */
Twitter* twitterCreate() {
  Twitter* twitter = (Twitter*)malloc(sizeof(Twitter));
  twitter->user = (struct User*)malloc(sizeof(struct User));
  twitter->user->next = NULL;
  twitter->tweet = (struct Tweet*)malloc(sizeof(struct Tweet));
  twitter->tweet->next = NULL;
  return twitter;
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
  struct Tweet* tweet = (struct Tweet*)malloc(sizeof(struct Tweet));
  tweet->userId = userId;
  tweet->tweetId = tweetId;
  tweet->next = obj->tweet->next;  //头插法,保证最后发布的推文在最前面
  obj->tweet->next = tweet;
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
  int* ret = (int*)calloc(10, sizeof(int));
  *retSize = 0;
  struct Tweet* tweet = obj->tweet->next;
  struct User* user = obj->user->next;
  while (user && user->id != userId) user = user->next;  //查找用户结点
  if (user == NULL) {                                    //未找到，当前用户未关注任何用户
    while (tweet && *retSize < 10) {
      if (tweet->userId == userId)  //用户自己发的推文
        ret[(*retSize)++] = tweet->tweetId;
      tweet = tweet->next;
    }
    return ret;
  }
  while (tweet && *retSize < 10) {
    if (tweet->userId == userId || user->followee[tweet->userId] == 1)  //用户自己及用户关注的人的推文
      ret[(*retSize)++] = tweet->tweetId;
    tweet = tweet->next;
  }
  return ret;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) {
  struct User* u = obj->user;
  while (u->next && u->id != followerId) u = u->next;  //用户链表中是否存在当前用户
  if (u->id == followerId)                             //存在：将关注的用户id散列到数组中，关注(1)
    u->followee[followeeId] = 1;
  else {  //不存在：新建用户结点，关注(1)，头插法插入用户链表
    struct User* user = (struct User*)malloc(sizeof(struct User));
    user->id = followerId;
    user->followee[followeeId] = 1;
    user->next = obj->user->next;
    obj->user->next = user;
  }
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
  struct User* u = obj->user;
  while (u->next && u->id != followerId) u = u->next;  //用户链表中是否存在当前用户
  if (u->id == followerId)                             //存在：取消关注(0)
    u->followee[followeeId] = 0;
}

void twitterFree(Twitter* obj) {
  if (obj && obj->user) {
    struct User* u;
    while (obj->user->next) {
      u = obj->user;
      obj->user = obj->user->next;
      free(u);
    }
    free(obj->user);
  }
  if (obj && obj->tweet) {
    struct Tweet* t;
    while (obj->tweet->next) {
      t = obj->tweet;
      obj->tweet = obj->tweet->next;
      free(t);
    }
    free(obj->tweet);
  }
  if (obj) free(obj);
}

/**
 * Your Twitter struct will be instantiated and called as such:
 * Twitter* obj = twitterCreate();
 * twitterPostTweet(obj, userId, tweetId);
 
 * int* param_2 = twitterGetNewsFeed(obj, userId, retSize);
 
 * twitterFollow(obj, followerId, followeeId);
 
 * twitterUnfollow(obj, followerId, followeeId);
 
 * twitterFree(obj);
*/
// @lc code=end
