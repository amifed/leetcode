//
// Created by dingjinyang on 2020/2/19.
//

#ifndef LEETCODE_MERGE_H
#define LEETCODE_MERGE_H
#include <stdio.h>
#include <stdlib.h>

/* 降序  */
int compDes(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/* 升序 */
int compAsc(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

/**
 * @params size size of array
 * @params seq:1->asc\0->dec  
 **/
void sort(int *a, int size, int seq)
{
    seq == 1 ? qsort(a, size, sizeof(int), compDes) : qsort(a, size, sizeof(int), compAsc);
}

#endif //LEETCODE_MERGE_H
