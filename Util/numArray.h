int numToArray(int n, int *nums)
{
    int i = 0;
    while (n != 0)
    {
        nums[i++] = n % 10;
        n /= 10;
    }
    return i;
}

int ArrayToNum(int *nums, int numsSize)
{
    int i, num = 0;
    for (i = numsSize - 1; i >= 0; i--)
        num = num * 10 + nums[i];
    return num;
}