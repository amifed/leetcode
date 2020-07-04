/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyCircularQueue {
  vector<int> q;
  int front, rear;

public:
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k) {
    q.resize(k + 1);
    front = 0, rear = 0;
  }

  /** Insert an element into the circular queue. Return true if the operation is
   * successful. */
  bool enQueue(int value) {
    if (isFull())
      return false;
    q[rear] = value;
    rear = (rear + 1) % q.size();
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is
   * successful. */
  bool deQueue() {
    if (isEmpty())
      return false;
    front = (front + 1) % q.size();
    return true;
  }

  /** Get the front item from the queue. */
  int Front() {
    if (isEmpty())
      return -1;
    return q[front];
  }

  /** Get the last item from the queue. */
  int Rear() {
    if (isEmpty())
      return -1;
    return q[(rear + q.size() - 1) % q.size()];
  }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() { return front == rear; }

  /** Checks whether the circular queue is full or not. */
  bool isFull() { return (rear + 1) % q.size() == front; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
