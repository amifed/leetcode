/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */
#include <bits/stdc++.h>
using namespace std;
class NestedInteger {
public:
  bool isInteger() const;
  int getInteger() const;
  const vector<NestedInteger> &getList() const;
};
// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
  stack<NestedInteger> st;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto i = nestedList.rbegin(); i != nestedList.rend(); i++)
      st.push(*i);
  }

  int next() {
    auto it = st.top();
    st.pop();
    return it.getInteger();
  }

  bool hasNext() {
    while (!st.empty()) {
      auto it = st.top();
      if (it.isInteger())
        return true;
      st.pop();
      auto nestedList = it.getList();
      for (auto i = nestedList.rbegin(); i != nestedList.rend(); i++)
        st.push(*i);
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
