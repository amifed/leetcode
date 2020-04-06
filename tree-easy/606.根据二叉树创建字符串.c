/*
 * @lc app=leetcode.cn id=606 lang=c
 *
 * [606] 根据二叉树创建字符串
 *
 * https://leetcode-cn.com/problems/construct-string-from-binary-tree/description/
 *
 * algorithms
 * Easy (52.79%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 19.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
 * 
 * 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 二叉树: [1,2,3,4]
 * ⁠      1
 * ⁠    /   \
 * ⁠   2     3
 * ⁠  /    
 * ⁠ 4     
 * 
 * 输出: "1(2(4))(3)"
 * 
 * 解释: 原本将是“1(2(4)())(3())”，
 * 在你省略所有不必要的空括号对之后，
 * 它将是“1(2(4))(3)”。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 二叉树: [1,2,3,null,4]
 * ⁠      1
 * ⁠    /   \
 * ⁠   2     3
 * ⁠    \  
 * ⁠     4 
 * 
 * 输出: "1(2()(4))(3)"
 * 
 * 解释: 和第一个示例相似，
 * 除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
 * 
 * 
 */
#include <stdlib.h>

#include "TreeNode.h"
// @lc code=start

#define MAX_SIZE 30000
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* t, char* dest) {
  if (t->left == NULL && t->right == NULL) {
    sprintf(dest, "%s%d", dest, t->val);
  } else if (t->left == NULL) {
    sprintf(dest, "%s%d%s", dest, t->val, "()(");
    dfs(t->right, dest);
    sprintf(dest, "%s%c", dest, ')');
  } else if (t->right == NULL) {
    sprintf(dest, "%s%d%c", dest, t->val, '(');
    dfs(t->left, dest);
    sprintf(dest, "%s%c", dest, ')');
  } else {
    sprintf(dest, "%s%d%c", dest, t->val, '(');
    dfs(t->left, dest);
    sprintf(dest, "%s%s", dest, ")(");
    dfs(t->right, dest);
    sprintf(dest, "%s%c", dest, ')');
  }
}

char* tree2str(struct TreeNode* t) {
  if (t == NULL) return "";
  char* str = (char*)calloc(MAX_SIZE, sizeof(char));
  dfs(t, str);
  return str;
}

// @lc code=end