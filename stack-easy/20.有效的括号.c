/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (41.25%)
 * Likes:    1468
 * Dislikes: 0
 * Total Accepted:    238.4K
 * Total Submissions: 577.9K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include <stdbool.h>
// @lc code=start

bool isValid(char *s)
{
    int top = -1, len = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * len);
    char temp;
    while (*s != '\0')
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            stack[++top] = *s; //left push
        }
        else
        {
            if (top < 0)
                return false;
            temp = stack[top--]; //right pop
            if ((temp == '(' && *s != ')') || (temp == '[' && *s != ']') || (temp == '{' && *s != '}'))
                return false;
        }
        s++;
    }
    if (top > -1)
        return false;
    return true;
}

// @lc code=end
