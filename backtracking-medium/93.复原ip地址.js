/*
 * @lc app=leetcode.cn id=93 lang=javascript
 *
 * [93] 复原IP地址
 */

// @lc code=start
/**
 * @param {string} s
 * @return {string[]}
 */
const restoreIpAddresses = function (s) {
  let result = [];
  const valid = (str) => {
    if (str.length > 3) return false;
    return str.startsWith("0") ? str.length === 1 : parseInt(str) < 256;
  };
  const backtracking = (index, dots, segments) => {
    if (dots === -1) {
      if (index === s.length) result.push(segments.join(".")); //字符全部用完才正确
      return;
    }
    for (let i = 1; i < 4; i++) {
      const sub = s.substr(index, i); //每次截取 1或2或3 个字符
      if (!valid(sub)) continue;
      segments.push(sub);
      backtracking(index + i, dots - 1, [...segments]);
      segments.pop();
    }
  };
  backtracking(0, 3, []);
  return result;
};
// @lc code=end
