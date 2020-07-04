/*
 * @lc app=leetcode.cn id=168 lang=c
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (37.19%)
 * Likes:    196
 * Dislikes: 0
 * Total Accepted:    22.5K
 * Total Submissions: 60.5K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */

// @lc code=start

void reverse(char *ch, int size)
{
    char temp;
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
    }
}
char *convertToTitle(int n)
{
    int i = 0;
    char *col = (char *)malloc(sizeof(char) * 8);
    while (n != 0)
    {
        col[i++] = 'A' + (n - 1) % 26;
        n = (n - 1) / 26;
    }
    col[i] = '\0';
    reverse(col, i);
    return col;
}

// @lc code=end
// 52 AZ