/**
 * 面试题13. 机器人的运动范围
 * 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
 * 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
 * 也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 
 * 例如，
 * 当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
 * 但它不能进入方格 [35, 38]，因为3+5+3+8=19。
 * 请问该机器人能够到达多少个格子？
 **/
int sumOfNumBit(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int movingCount(int m, int n, int k) {
  int i, j, cnt = 0, **dp = (int **)malloc(sizeof(int *) * m);
  for (i = 0; i < m; i++) {
    dp[i] = (int *)calloc(n, sizeof(int));
    for (j = 0; j < n; j++) {
      if (sumOfNumBit(i) + sumOfNumBit(j) <= k) {                                                            //坐标合法
        if ((i == 0 && j == 0) || (i - 1 >= 0 && dp[i - 1][j] == 1) || (j - 1 >= 0 && dp[i][j - 1] == 1)) {  //原点，上方，左方
          cnt++;
          dp[i][j] = 1;
        }
      }
    }
  }
  return cnt;
}