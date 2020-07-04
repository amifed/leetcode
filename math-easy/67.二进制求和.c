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

int Max(int a, int b) { return a > b ? a : b; }
char *addBinary(char *a, char *b)
{
    int i, j, k, carry = 0, len1 = strlen(a), len2 = strlen(b);
    char temp, *res = (char *)malloc(sizeof(char) * 1000);
    for (i = len1 - 1, j = len2 - 1, k = 0; i >= 0 && j >= 0; i--, j--)
    {
        carry += ((a[i] - '0') + (b[j] - '0'));
        if (carry % 2 == 1)
            res[k++] = '1';
        else
            res[k++] = '0';
        carry /= 2;
    }
    for (; i >= 0; i--)
    {
        carry += (a[i] - '0');
        if (carry % 2 == 1)
            res[k++] = '1';
        else
            res[k++] = '0';
        carry /= 2;
    }
    for (; j >= 0; j--)
    {
        carry += (b[j] - '0');
        if (carry % 2 == 1)
            res[k++] = '1';
        else
            res[k++] = '0';
        carry /= 2;
    }
    if (carry == 1)
        res[k++] = '1';
    res[k] = '\0';
    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        temp = res[i];
        res[i] = res[j];
        res[j] = temp;
    }
    return res;
}

// @lc code=end
// "11"\n"1"
// "1010"\n"1011"
// "1111"\n"11"