/*
 * @lc app=leetcode.cn id=1424 lang=javascript
 *
 * [1424] 对角线遍历 II
 */

// @lc code=start
/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var findDiagonalOrder = function (nums) {
  if (nums.length === 0) return [];
  let arrays = [],
    result = [];
  // 根据下标和 聚类
  for (let i = 0; i < nums.length; i++) {
    let rows = nums[i];
    for (let j = 0; j < rows.length; j++) {
      if (!arrays[i + j]) arrays[i + j] = [];
      arrays[i + j].push(nums[i][j]);
    }
  }
  // 二维数组扁平化
  for (const rows of arrays) {
    result.push(...rows.reverse()); //注意这里每个子数组都是倒序的，需要反转
  }
  return result;
};

// @lc code=end
