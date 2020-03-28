/*
 * @lc app=leetcode.cn id=12 lang=c
 *
 * [12] 整数转罗马数字
 */

// @lc code=start


char * intToRoman(int num){
    int i = 0, j, p = 0, nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *s = (char *)malloc(sizeof(char) * 32);
    char *roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    while (num > 0)
    {
        if (num >= nums[i])
        {
            num -= nums[i];
            for (j = 0; roman[i][j] != '\0';)
                s[p++] = roman[i][j++];
        }
        else
            i++;
    }
    s[p] = '\0';
    return s;
}


// @lc code=end

