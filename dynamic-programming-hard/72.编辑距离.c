/*
 * @lc app=leetcode.cn id=72 lang=c
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (56.70%)
 * Likes:    656
 * Dislikes: 0
 * Total Accepted:    39.4K
 * Total Submissions: 69K
 * Testcase Example:  '"horse"\n"ros"'
 * Testcase Example:  '"intention"\n"execution"'
 *
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2：
 * 
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 */

// @lc code=start
int Min(int a, int b, int c) { return a > b ? (b > c ? c : b) : (a > c ? c : a); }
int minDistance(char *word1, char *word2) {
  int i, j, m = strlen(word1), n = strlen(word2);
  int **dp = (int **)malloc(sizeof(int *) * (m + 1));
  //初始值：word1 前i个字符 转换成 word2前0个字符，全部删除
  for (i = 0; i <= m; i++) {
    dp[i] = (int *)calloc(n + 1, sizeof(int));
    dp[i][0] = i;
  }
  //初始值：word1 前0个字符 转换成 word2前j个字符，全部插入
  for (j = 0; j <= n; j++) dp[0][j] = j;
  // 如果当前字符word1与word2相同，本次无操作但记录上一次次数
  // 否则 取插入，删除，替换 当前字符所需步数的最小值
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : 1 + Min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
    }
  }
  return dp[m][n];
}
/**
 * dp[i-1][j-1] 替换操作，dp[i-1][j] 删除操作，dp[i][j-1] 插入操作：
 * 以 word1 为 "horse"，word2 为 "ros"，且 dp[5][3] 为例，即要将 word1的前 5 个字符转换为 word2的前 3 个字符，也就是将 horse 转换为 ros，因此有：
 * (1) dp[i-1][j-1]，即先将 word1 的前 4 个字符 "hors" 转换为 word2 的前 2 个字符 "ro"，然后将 word1 第五个字符 word1[4] 由 'e' 替换为 's'（即替换为 word2 的第三个字符，word2[2]）
 * (2) dp[i][j-1]，即先将 word1 的前 5 个字符 "horse" 转换为 word2 的前 2 个字符 "ro"，然后在 word1 末尾插入一个 's';
 * (3) dp[i-1][j]，即先将 word1 的前 4 个字符 "hors" 转换为 word2 的前 3 个字符 "ros"，然后删除 word1 的第 5 个字符 'e';
 */

// @lc code=end
