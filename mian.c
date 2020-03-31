#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "ListNode.h"
#include "linked-list-medium/24.两两交换链表中的节点.c"
#define Min2(a, b) (a < b ? a : b)
#define Min3(a, b, c) (a > b ? (b > c ? c : b) : (a > c ? c : a));
#define Max2(a, b) (a > b ? a : b)
int main()
{
    struct LinkNode *L = tailInsertCreateList(4);
    outputLinkedList(swapPairs(L));
    return 0;
}