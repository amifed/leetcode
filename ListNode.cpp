#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};
/**
 * 尾插法 创建单链表 （无头结点）
 * @params vector<int> 结点个数
 **/
ListNode *tailInsertCreateList(vector<int> nodes) {
    ListNode *L = new ListNode;
    ListNode *r = L;
    for (auto &&i : nodes) {
        ListNode *p = new ListNode(i);
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return L->next;
}
ListNode *headInsertCreateList(vector<int> nodes){}
/**
 * 输出单链表
 **/
void output(ListNode *L) {
    ListNode *p = L;
    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}