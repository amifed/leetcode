/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
    int numComponents(ListNode *head, vector<int> &G) {
        int ret = 0;
        unordered_set<int> us(G.begin(), G.end());
        while (head != NULL) {
            while (head != NULL && us.find(head->val) == us.end())
                head = head->next;
            if (head == NULL)
                break;
            while (head != NULL && us.find(head->val) != us.end())
                head = head->next;
            ret++;
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

int main()

{

    vector<int> G;

    int m, data, res;

    ListNode *head = createByTail();

    cin >> m;

    for (int i = 0; i < m; i++)

    {

        cin >> data;

        G.push_back(data);
    }

    res = Solution().numComponents(head, G);

    cout << res << endl;

    return 0;
}