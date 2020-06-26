/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    /**
     * reverse latter list
     */
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return;
        // find middle node
        ListNode *pre = nullptr, *slow = head, *fast = head;
        while (fast && fast->next)
            pre = slow, slow = slow->next, fast = fast->next->next;
        pre->next = nullptr;
        // reorder list
        ListNode *h1 = head, *h2 = reverseList(slow);
        ListNode *L = new ListNode(0, head);
        ListNode *h = L;
        while (h1) {
            ListNode *p = h1, *q = h2;
            h1 = h1->next, h2 = h2->next;
            h->next = p;
            p->next = q;
            h = q;
        }
    }
};
// @lc code=end
ListNode *createByTail() {
    ListNode *head;
    ListNode *p1, *p2;
    int n = 0, num;
    int len;
    cin >> len;
    head = NULL;
    while (n < len && cin >> num) {
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
void displayLink(ListNode *head) {

    ListNode *p;
    p = head;
    cout << "head-->";
    while (p != NULL) {
        cout << p->val << "-->";
        p = p->next;
    }
    cout << "tail\n";
}
int main() {

    ListNode *head = createByTail();
    Solution().reorderList(head);
    displayLink(head);
    return 0;
}