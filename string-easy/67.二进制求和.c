/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.30%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    72K
 * Total Submissions: 137.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start

char *addBinary(const char *a, const char *b) {
  int lena = strlen(a), lenb = strlen(b);
  int len = lena > lenb ? lena : lenb;
  int i, j, k;
  char *temp = (char *)malloc(sizeof(char) * len);
  for (i = lena - 1, j = lenb - 1, k = len - 1; i >= 0 && j >= 0; --i, --j, --k) {
    if (a[i] == '1' && b[j] == '1') {
      temp[k] = '2';
    } else if (a[i] == '0' && b[j] == '0') {
      temp[k] = '0';
    } else {
      temp[k] = '1';
    }
  }
  for (; i >= 0; --i, --k) {
    temp[k] = a[i];
  }
  for (; j >= 0; --j, --k) {
    temp[k] = b[j];
  }

  // 获得相加后的字符串
  for (int l = 0; l < len; ++l) {
    printf("%c", temp[l]);
  }

  int bit = 0;
  for (int l = len - 1; l >= 0; --l) {
    if (temp[l] == '2' && bit == 0) {
      temp[l] = '0';
      bit = 1;
    } else if (temp[l] == '2' && bit == 1) {
      temp[l] = '1';
      //            bit =1;
    } else if (temp[l] == '1' && bit == 1) {
      temp[l] = '0';
      //            bit = 1;
    } else if (temp[l] == '0' && bit == 1) {
      temp[l] = '1';
      bit = 0;
    }
  }

  if (bit == 1) {
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    res[0] = '1';
    for (int l = 1; l <= len + 1; ++l) {
      res[l] = temp[l - 1];
    }
    return res;
  }

  return temp;
}

// @lc code=end
