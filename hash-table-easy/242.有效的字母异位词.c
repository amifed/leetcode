/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (59.10%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    86.2K
 * Total Submissions: 145.7K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
#include <stdbool.h>
// @lc code=start

bool isAnagram(char *s, char *t)
{
    int i, hash1[26] = {0}, hash2[26] = {0};
    while (*s != '\0' && *t != '\0')
    {
        hash1[(*s) - 'a']++;
        hash2[(*t) - 'a']++;
        s++;
        t++;
    }
    if (*s != '\0' || *t != '\0')
        return false;
    for (i = 0; i < 26; i++)
        if (hash1[i] != hash2[i])
            return false;
    return true;
}

// @lc code=end
// "rat"\n"car"