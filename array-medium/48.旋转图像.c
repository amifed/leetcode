/*
 * @lc app=leetcode.cn id=48 lang=c
 *
 * [48] 旋转图像
 */

// @lc code=start

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
  for (int i = 0; i < matrixSize; i++)
    for (int j = i + 1; j < matrixColSize[i]; j++)
      swap(&matrix[i][j], &matrix[j][i]);
  for (int i = 0; i < matrixSize; i++)
    for (int j = 0, k = matrixColSize[i] - 1; j < k; j++, k--)
      swap(&matrix[i][j], &matrix[i][k]);
}

// @lc code=end
