int issushu(int k)
{
    if (k == 0 || k == 1)
        return 0;
    for (int i = 2; i <= k / 2; i++)
    {
        if (k % i == 0)
            return 0;
    }
    return 1;
}