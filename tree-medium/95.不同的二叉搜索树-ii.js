/*
 * @lc app=leetcode.cn id=95 lang=javascript
 *
 * [95] 不同的二叉搜索树 II
 */
class TreeNode {
  constructor(val) {
    this.val = val;
    this.left = this.right = null;
  }
}
// @lc code=start
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function (n) {
  const generate = (start, end) => {
    let result = [];
    if (start > end) {
      result.push(null);
      return result;
    }
    for (let i = start; i <= end; i++) {
      const left_trees = generate(start, i - 1);
      const right_trees = generate(i + 1, end);
      for (const left of left_trees) {
        for (const right of right_trees) {
          let tree = new TreeNode(i);
          tree.left = left;
          tree.right = right;
          result.push(tree);
        }
      }
    }
    return result;
  };
  return n === 0 ? [] : generate(1, n);
};
// @lc code=end

// @after-stub-for-debug-begin
module.exports = generateTrees;
// @after-stub-for-debug-end