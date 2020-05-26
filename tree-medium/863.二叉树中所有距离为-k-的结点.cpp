/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
TreeNode *createBiTree() {
  string val;
  cin >> val;
  if (val != "#") {
    TreeNode *T = new TreeNode(stoi(val));
    T->left = createBiTree();
    T->right = createBiTree();
    return T;
  } else
    return NULL;
}
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  unordered_map<TreeNode *, TreeNode *> parent;

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    dfs(root, NULL); //记录父结点
    queue<TreeNode *> Q;
    unordered_set<TreeNode *> visited;
    Q.push(target); // target结点入队，从 target 结点开始向外延伸
    visited.insert(target);
    while (!Q.empty()) {
      if (K-- == 0) { // 延伸 K 次，队中全部结点即为所求
        vector<int> ret;
        while (!Q.empty()) {
          ret.push_back(Q.front()->val);
          Q.pop();
        }
        return ret;
      } else {
        int n = Q.size(); // 将当前队中所有结点向外延伸 1 个结点
        for (int i = 0; i < n; i++) {
          TreeNode *node = Q.front();
          Q.pop();
          if (node->left && visited.find(node->left) == visited.end()) {
            Q.push(node->left);
            visited.insert(node->left);
          }
          if (node->right && visited.find(node->right) == visited.end()) {
            Q.push(node->right);
            visited.insert(node->right);
          }
          if (parent[node] != NULL &&
              visited.find(parent[node]) == visited.end()) {
            Q.push(parent[node]);
            visited.insert(parent[node]);
          }
        }
      }
    }
    return vector<int>();
  }
  void dfs(TreeNode *root, TreeNode *pre) {
    if (root) {
      parent.insert({root, pre});
      dfs(root->left, root);
      dfs(root->right, root);
    }
  }
};
// @lc code=end
int main() {
  // 3 5 6 # # 2 7 # # 4 # # 1 0 # # 8 # # #
  TreeNode *T = createBiTree();
  Solution().distanceK(T, T->left, 2);
  return 0;
}