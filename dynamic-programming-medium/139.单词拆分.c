/*
 * @lc app=leetcode.cn id=139 lang=c
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (44.11%)
 * Likes:    378
 * Dislikes: 0
 * Total Accepted:    45.1K
 * Total Submissions: 101.6K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */
#include <stdbool.h>
// @lc code=start

bool wordBreak(char *s, char **wordDict, int wordDictSize) {
  int i, j, k, len, slen = strlen(s);
  bool dp[slen + 1];
  memset(dp, false, sizeof(dp));
  dp[0] = true;
  for (i = 1; i <= slen; i++) {
    for (j = 0; j < wordDictSize; j++) {
      len = strlen(wordDict[j]);
      k = i - len;
      if (k < 0)
        continue;
      // strncmp , 返回字符串的差值 ，即相同时返回 0
      dp[i] = (dp[k] && !strncmp(s + k, wordDict[j], len)) || dp[i];
    }
  }
  for (i = 0; i <= slen; i++)
    printf("%d ", dp[i]);
  return dp[slen];
}

// @lc code=end
