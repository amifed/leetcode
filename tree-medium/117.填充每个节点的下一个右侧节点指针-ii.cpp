/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  public:
  Node* connect(Node* root) {
    if (root == NULL) return root;
    queue<Node*> Q;
    Node* last = root; //
    Q.push(root);
    while (!Q.empty()) {
      Node* p = Q.front();
      Q.pop();
      if (!Q.empty() && p != last) p->next = Q.front();
      if (p->left) Q.push(p->left);
      if (p->right) Q.push(p->right);
      if (last == p) last = Q.back();
    }
    return root;
  }
};
// @lc code=end
