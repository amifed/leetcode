/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (38.20%)
 * Likes:    750
 * Dislikes: 0
 * Total Accepted:    144.2K
 * Total Submissions: 377.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//双指针法：先让一个指针走n步，两指针再同时后移，先走的指针到达表尾时，后指针就是倒数第n个结点
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    if (n == 0)
        return head;
    struct ListNode *front = head, *back = head, *s = head;
    for (; n > 0 && front != NULL; --n)
        front = front->next;
    while (front != NULL)
    {
        front = front->next;
        s = back;
        back = back->next;
    }
    if (s == back)
        return s->next;
    s->next = back->next;
    free(back);
    return head;
}

// @lc code=end

//Test
//[1]\n1
//[1,2]\n1
//[1,2]\n2