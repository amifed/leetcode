#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "dynamic-programming-medium/1111.有效括号的嵌套深度.c"
#define Min2(a, b) (a < b ? a : b)
#define Min3(a, b, c) (a > b ? (b > c ? c : b) : (a > c ? c : a));
#define Max2(a, b) (a > b ? a : b)
int main()
{
    char ch;
    printf("请输入一个字符:");
    ch = getchar();
    if (ch >= '0' && ch <= '9')
        printf("1\n");
    else
        printf("0\n");
}