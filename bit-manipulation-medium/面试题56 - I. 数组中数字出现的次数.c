/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize) {
  int i, xor = 0;
  for (i = 0; i < numsSize; i++)
    xor ^= nums[i];
  int dif = 1;
  while ((dif & xor) == 0) dif <<= 1;
  int* result = (int*)calloc(2, sizeof(int));
  for (i = 0; i < numsSize; i++)
    if (nums[i] & dif)
      result[0] ^= nums[i];
    else
      result[1] ^= nums[i];
  *returnSize = 2;
  return result;
}
