/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MinStack {
  private:
  stack<int> s, ms;

  public:
  /** initialize your data structure here. */
  MinStack() {
  }

  void push(int x) {
    if (ms.size() == 0 || x <= ms.top()) ms.push(x);
    s.push(x);
  }

  void pop() {
    if (s.top() == ms.top()) ms.pop();
    s.pop();
  }

  int top() {
    return s.top();
  }

  int getMin() {
    return ms.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
