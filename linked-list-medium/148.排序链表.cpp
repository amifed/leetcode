/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        // cut list at middle node
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL)
            slow = slow->next, fast = fast->next->next;
        ListNode *mid = slow->next;
        slow->next = NULL;

        // recursive
        ListNode *left = sortList(head), *right = sortList(mid);

        // merge
        ListNode *ret = new ListNode(0);
        ListNode *p = ret;
        while (left != NULL && right != NULL) {
            if (left->val < right->val)
                p->next = left, left = left->next;
            else
                p->next = right, right = right->next;
            p = p->next;
        }
        p->next = left != NULL ? left : right;
        return ret->next;
    }
};
// @lc code=end
ListNode *createByTail()

{

    ListNode *head;

    ListNode *p1, *p2;

    int n = 0, num;

    int len;

    cin >> len;

    head = NULL;

    while (n < len && cin >> num)

    {

        p1 = new ListNode(num);

        n = n + 1;

        if (n == 1)

            head = p1;

        else

            p2->next = p1;

        p2 = p1;
    }

    return head;
}

void displayLink(ListNode *head)

{

    ListNode *p;

    p = head;

    cout << "head-->";

    while (p != NULL)

    {

        cout << p->val << "-->";

        p = p->next;
    }

    cout << "tail\n";
}

int main()

{

    ListNode *head = createByTail();

    head = Solution().sortList(head);

    displayLink(head);

    return 0;
}