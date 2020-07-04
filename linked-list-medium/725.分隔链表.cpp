/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        int n = 0;
        ListNode *p = root;
        while (p)
            p = p->next, n++;
        int width = n / k, remainder = n % k;
        vector<ListNode *> ret;
        p = root;
        for (int i = 0; i < k; i++) {
            ListNode *head = p;
            for (int j = 0; j < width + (i < remainder) - 1; j++)
                if (p)
                    p = p->next;
            if (p) {
                ListNode *pre = p;
                p = p->next;
                pre->next = NULL;
            }
            ret.push_back(head);
        }
        return ret;
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

void display(vector<ListNode *> lnVec)

{

    for (int i = 0; i < lnVec.size(); i++)

    {

        ListNode *p;

        p = lnVec[i];

        cout << "head-->";

        while (p != NULL)

        {

            cout << p->val << "-->";

            p = p->next;
        }

        cout << "tail\n";
    }
}

int main()

{

    vector<int> G;

    int k, data, res;

    ListNode *head = createByTail();

    cin >> k;

    vector<ListNode *> lnVec = Solution().splitListToParts(head, k);

    display(lnVec);

    return 0;
}
