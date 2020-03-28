/*
 * @lc app=leetcode.cn id=43 lang=c
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (41.95%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    51.8K
 * Total Submissions: 123.4K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start

char *multiply(char *num1, char *num2)
{
    if (*num1 == '0' || *num2 == '0')
        return "0";
    int i, j, p = strlen(num1), q = strlen(num2), num[200];
    char *res;
    memset(num, -1, sizeof(num));
    //从低位到高位 乘法
    for (i = p - 1; i >= 0; i--)
    {
        for (j = q - 1; j >= 0; j--)
        {
            if (num[(p - i - 1) + (q - j - 1)] == -1)
                num[(p - i - 1) + (q - j - 1)] = (num1[i] - '0') * (num2[j] - '0');
            else
                num[(p - i - 1) + (q - j - 1)] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    //处理进位
    for (i = 0; num[i] != -1; i++)
    {
        if (num[i] > 9)
        {
            if (num[i + 1] == -1)
                num[i + 1] = num[i] / 10;
            else
                num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    res = (char *)malloc(sizeof(char) * (i + 1));
    for (i--, j = 0; i >= 0;)
        res[j++] = num[i--] + '0';
    res[j] = '\0';
    return res;
}

// @lc code=end
