/*
 * @lc app=leetcode.cn id=232 lang=c
 *
 * [232] 用栈实现队列
 *
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (63.59%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    38.3K
 * Total Submissions: 60.1K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用栈实现队列的下列操作：
 * 
 * 
 * push(x) -- 将一个元素放入队列的尾部。
 * pop() -- 从队列首部移除元素。
 * peek() -- 返回队列首部的元素。
 * empty() -- 返回队列是否为空。
 * 
 * 
 * 示例:
 * 
 * MyQueue queue = new MyQueue();
 * 
 * queue.push(1);
 * queue.push(2);  
 * queue.peek();  // 返回 1
 * queue.pop();   // 返回 1
 * queue.empty(); // 返回 false
 * 
 * 说明:
 * 
 * 
 * 你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty
 * 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
 * 
 * 
 */
#include <stdbool.h>
// @lc code=start
#define MAX_SIZE 100
typedef struct
{
    int top1;
    int top2;
    int stack1[MAX_SIZE];
    int stack2[MAX_SIZE];
} MyQueue;

/** Initialize your data structure here. */

MyQueue *myQueueCreate()
{
    MyQueue *myQueue = (MyQueue *)malloc(sizeof(MyQueue));
    myQueue->top1 = -1;
    myQueue->top2 = -1;
    return myQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x)
{
    //栈1不满：入栈
    if (obj->top1 < MAX_SIZE - 1)
        obj->stack1[++(obj->top1)] = x;
    //栈1满，栈2空：将栈1元素全部入栈2后入栈1
    else if (obj->top1 >= MAX_SIZE - 1 && obj->top2 == -1)
    {
        while (obj->top1 != -1)
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        obj->stack1[++(obj->top1)] = x;
    }
    //否则，无法入队
    else
        return;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj)
{
    //栈2不空，出栈
    if (obj->top2 != -1)
        return obj->stack2[(obj->top2)--];
    //栈2空，将栈1元素全部入栈2，再从栈2出栈
    else
    {
        while (obj->top1 != -1)
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        return obj->stack2[(obj->top2)--];
    }
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj)
{
    //栈2不空，取栈2栈顶元素
    if (obj->top2 != -1)
        return obj->stack2[(obj->top2)];
    //栈2空，取栈1元素
    else
        return obj->stack1[0];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *obj)
{
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
// @lc code=end
