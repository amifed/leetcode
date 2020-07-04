/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class RandomizedCollection {
private:
  vector<int> collection;
  unordered_map<int, unordered_set<int>> um;

public:
  /** Initialize your data structure here. */
  RandomizedCollection() {}

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {
    if (um.find(val) == um.end())
      um.insert({val, unordered_set<int>()});
    um[val].insert(collection.size());
    collection.push_back(val);
    return um[val].size() == 1;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    if (um.find(val) == um.end() || um[val].size() == 0)
      return false;
    int index = *um[val].begin();
    um[val].erase(um[val].begin()); //删除原set
    collection[index] = collection.back();
    um[collection[index]].insert(index);
    um[collection[index]].erase(
        um[collection[index]].find(collection.size() - 1));
    collection.pop_back();
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() { return collection[rand() % collection.size()]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
