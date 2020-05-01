/**
 * 最长公共子串
 */
int longestCommonSubstring(char *str1, char *str2) {
  int i, j, len1 = strlen(str1), len2 = strlen(str2), max = 0;
  int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
  for (i = 0; i <= len1; i++)
    dp[i] = (int *)calloc(len2 + 1, sizeof(int));
  for (i = 1; i <= len1; i++) {
    for (j = 1; j <= len2; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        max = Max(max, dp[i][j]);
      } else
        dp[i][j] = 0;
    }
  }
  return max;
}