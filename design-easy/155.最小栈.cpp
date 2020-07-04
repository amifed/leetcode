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
  stack<int> stack, min_stack;

  public:
  /** initialize your data structure here. */
  MinStack() {
  }

  void push(int x) {
    stack.push(x);
    if (min_stack.size() == 0 || x <= min_stack.top())
      min_stack.push(x);
  }

  void pop() {
    if (stack.top() == min_stack.top()) min_stack.pop();
    stack.pop();
  }

  int top() {
    return stack.top();
  }

  int getMin() {
    return min_stack.top();
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
