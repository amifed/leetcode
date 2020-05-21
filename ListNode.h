struct ListNode {
  int val;
  struct ListNode *next;
};

/**
 * 尾插法 创建单链表 （无头结点）
 * @params int n 结点个数
 **/
struct ListNode *tailInsertCreateList(int n) {
  struct ListNode *r = malloc(sizeof(struct ListNode));
  struct ListNode *L = r;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &r->val);
    if (i != n - 1) {
      struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
      r->next = p;
      r = p;
    } else
      r->next = NULL;
  }
  return L;
}

/**
 * 输出单链表
 **/
void outputLinkedList(struct ListNode *L) {
  struct ListNode *p = L;
  while (p != NULL) {
    printf("%d -> ", p->val);
    p = p->next;
  }
  printf("NULL\n");
}