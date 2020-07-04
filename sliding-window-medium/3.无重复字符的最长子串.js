/*
 * @lc app=leetcode.cn id=3 lang=javascript
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

/**
 * @param {string} s
 * @return {number}
 */
const lengthOfLongestSubstring = function (s) {
  let window = [],
    max = Number.MIN_SAFE_INTEGER;
  for (const c of s) {
    let index = window.indexOf(c);
    if (index !== -1) window.splice(0, index + 1);
    window.push(c);
    max = Math.max(window.length, max);
  }
  return max;
};

// @lc code=end
