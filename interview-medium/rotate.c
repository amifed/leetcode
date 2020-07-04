/**
 * 面试题 01.07. 旋转矩阵
 * 给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
 * 不占用额外内存空间能否做到？
 */
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
  int i, j;
  for (i = 0; i < matrixSize; i++)
    for (j = 0; j < matrixColSize[i] && j < i; j++)
      swap(&matrix[i][j], &matrix[j][i]);
  for (i = 0; i < matrixSize; i++)
    for (j = 0; j < matrixColSize[i] / 2; j++)
      swap(&matrix[i][j], &matrix[i][matrixSize - j - 1]);
}