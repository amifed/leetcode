/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        ListNode *odd = new ListNode, *even = new ListNode;
        ListNode *p = odd, *q = even;
        while (head) {
            p->next = head, p = p->next;
            head = head->next;
            q->next = head, q = q->next;
            if (head != nullptr)
                head = head->next;
        }
        p->next = even->next;
        return odd->next;
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

    head = Solution().oddEvenList(head);

    displayLink(head);

    return 0;
}
