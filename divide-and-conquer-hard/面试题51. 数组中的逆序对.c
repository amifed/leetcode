/**
 * @lc app=leetcode.cn id=100318 lang=c
 * 
 * [面试题51] 数组中的逆序对
 * 
 */

// @lc code=start
int mergeAndCount(int* nums, int numsSize, int* temp, int left, int mid, int right) {
  memcpy(temp + left, nums + left, (right - left + 1) * sizeof(int));
  int i = left, j = mid + 1, k = left, count = 0;
  while (k <= right) {
    if (i == mid + 1)
      nums[k++] = temp[j++];
    else if (j == right + 1)
      nums[k++] = temp[i++];
    else if (temp[i] <= temp[j])
      nums[k++] = temp[i++];
    else {
      nums[k++] = temp[j++];
      count += (mid - i + 1);
    }
  }
  return count;
}
int mergeSort(int* nums, int numsSize, int* temp, int left, int right) {
  if (left == right) return 0;
  int mid = left + (right - left) / 2;
  int leftPairs = mergeSort(nums, numsSize, temp, left, mid);
  int rightPairs = mergeSort(nums, numsSize, temp, mid + 1, right);
  if (nums[mid] <= nums[mid + 1]) return leftPairs + rightPairs;
  int crossPairs = mergeAndCount(nums, numsSize, temp, left, mid, right);
  return leftPairs + rightPairs + crossPairs;
}
int reversePairs(int* nums, int numsSize) {
  if (numsSize < 2) return 0;
  int* temp = (int*)calloc(numsSize, sizeof(int));
  return mergeSort(nums, numsSize, temp, 0, numsSize - 1);
}

// @lc code=end