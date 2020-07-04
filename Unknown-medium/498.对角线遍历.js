/*
 * @lc app=leetcode.cn id=498 lang=javascript
 *
 * [498] 对角线遍历
 */

// @lc code=start
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var findDiagonalOrder = function (matrix) {
  if (matrix.length === 0) return [];
  let arrays = [],
    result = [];
  // 根据下标和 聚类
  for (let i = 0; i < matrix.length; i++) {
    let rows = matrix[i];
    for (let j = 0; j < rows.length; j++) {
      if (!arrays[i + j]) arrays[i + j] = [];
      arrays[i + j].push(matrix[i][j]);
    }
  }
  // 二维数组扁平化
  for (let i = 0; i < arrays.length; i++) {
    if (i % 2 === 0) result.push(...arrays[i].reverse());
    //注意这里每个子数组都是倒序的，需要反转
    else result.push(...arrays[i]);
  }
  return result;
};
// @lc code=end
console.log(
  findDiagonalOrder([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
  ])
);
