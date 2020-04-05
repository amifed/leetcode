/*
 * @lc app=leetcode.cn id=460 lang=c
 *
 * [460] LFU缓存
 *
 * https://leetcode-cn.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (34.37%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    4.1K
 * Total Submissions: 11.4K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
 * 
 * get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
 * put(key, value) -
 * 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
 * 
 * 进阶：
 * 你是否可以在 O(1) 时间复杂度内执行两项操作？
 * 
 * 示例：
 * 
 * 
 * LFUCache cache = new LFUCache( 2 /* capacity (缓存容量) );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回 1
 * cache.put(3, 3);    // 去除 key 2
 * cache.get(2);       // 返回 -1 (未找到key 2)
 * cache.get(3);       // 返回 3
 * cache.put(4, 4);    // 去除 key 1
 * cache.get(1);       // 返回 -1 (未找到 key 1)
 * cache.get(3);       // 返回 3
 * cache.get(4);       // 返回 4
 * 
 */
#include <stdlib.h>
// @lc code=start
// 双向链表
struct DListNode {
  int key;                         //键
  int value;                       //值
  int freq;                        //访问频率
  struct DListNode *prior, *next;  //前驱，后继
};

typedef struct {
  struct DListNode* head;
  int capacity;
} LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
  LFUCache* cache = (LFUCache*)malloc(sizeof(LFUCache));
  // 初始化设置头结点
  cache->capacity = capacity;
  cache->head = (struct DListNode*)malloc(sizeof(struct DListNode));
  cache->head->prior = NULL;
  cache->head->next = NULL;
  return cache;
}

// 结点提升，插入排序的感觉，相同频率的放在同频率的最前面
void lFUCaacheUp(LFUCache* obj, struct DListNode* p) {
  struct DListNode* q;
  p->freq++;
  if (p->next) {  //如果当前结点是最后一个结点，
    p->next->prior = p->prior;
    p->prior->next = p->next;  //将p结点从链表上摘下
  } else
    p->prior->next = NULL;
  q = p->prior;
  while (q != obj->head && q->freq <= p->freq)  //向前查找p结点的插入位置
    q = q->prior;
  p->next = q->next;  //将p结点插入，排在同频率的第一个
  if (q->next != NULL)
    q->next->prior = p;
  p->prior = q;
  q->next = p;
}

int lFUCacheGet(LFUCache* obj, int key) {
  int count = 0;
  struct DListNode *p = obj->head->next, *q;
  // 遍历链表，查找元素
  while (p && p->key != key && count < obj->capacity) {
    p = p->next;
    count++;
  }
  // 不存在返回 -1
  if (p == NULL || count == obj->capacity) return -1;
  // 存在：访问频率加一，按访问频率调整链表，返回值
  lFUCaacheUp(obj, p);
  return p->value;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
  int count = 0;
  struct DListNode *p = obj->head, *q;
  // 先遍历链表找 key 是否存在
  while (p->next != NULL && p->next->key != key && count < obj->capacity) {
    p = p->next;
    count++;
  }
  // key已存在更新 结点，按访问频率调整链表
  if (p->next != NULL && p->next->key == key && count < obj->capacity) {  //key值已存在
    p->next->value = value;
    lFUCaacheUp(obj, p->next);
    return;
  }
  // key不存在，重新找到链表插入位置：仅访问过一次的结点（只有一次put）的最前面
  count = 0;
  p = obj->head;
  while (p->next != NULL && p->next->freq > 1 && count < obj->capacity) {
    p = p->next;
    count++;
  }
  if (count == obj->capacity) {  //到达表尾，直接覆盖尾结点
    p->key = key;
    p->value = value;
    p->freq = 1;
  } else {  //未到达表尾
    // 创建结点，存值
    struct DListNode* s = (struct DListNode*)malloc(sizeof(struct DListNode));
    s->key = key;
    s->value = value;
    s->freq = 1;
    // 插入
    s->next = p->next;
    s->prior = p;
    p->next = s;
    if (s->next)
      s->next->prior = s;
    else
      s->next = NULL;
  }
}

void lFUCacheFree(LFUCache* obj) {
  if (obj == NULL) return;
  struct DListNode* s;
  while (obj->head) {
    s = obj->head;
    obj->head = obj->head->next;
    free(s);
  }
  free(obj);
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
  
 * lFUCachePut(obj, key, value);
  
 * lFUCacheFree(obj);
*/
// @lc code=end
// ["LFUCache","put","put","put","put","get"]\n[[2],[3,1],[2,1],[2,2],[4,4],[2]]
//["LFUCache","put","put","get","get","get","put","put","get","get","get","get"]\n[[3],[2,2],[1,1],[2],[1],[2],[3,3],[4,4],[3],[2],[1],[4]]
// ["LFUCache","put","put","get","put","put","get"]\n[[2],[2,1],[2,2],[2],[1,1],[2,1],[2]]
// ["LFUCache","put","put","put","put","put","get","put","get","get","put","get","put","put"]\n[[10],[10, 13],[3, 17],[6, 11],[10, 5],[9, 10],[13],[2, 19],[2],[3],[5, 25],[8],[9, 22],[5, 5]]
//["LFUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]\n[[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]
//
//
