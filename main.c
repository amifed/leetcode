#include <stdio.h>
#define MAX_SIZE 50
typedef int ElemType;
struct SqList {
    ElemType data[MAX_SIZE];
    int length;
};
void increment(int a[], int size) {
    int i;
    for (i = 0; i < size; i++)
        a[i] += 1;
}
int main() {
    struct SqList sl;
    int n = 5;
    for (int i = 0; i < n; i++) {
        sl.data[i] = i;
        sl.length++;
    } 

    return 0;
}