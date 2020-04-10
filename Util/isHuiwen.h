int isHuiwen(int num)
{
    int rev = 0, temp = num;
    while (temp != 0)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == num;
}