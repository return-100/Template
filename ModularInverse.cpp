long long bigMod(long long base, long long pow)
{
    long long ret = 1;

    while (pow)
    {
        if (pow & 1)
            ret *= base, ret %= mod;

        base *= base, base %= mod;
        pow >>= 1;
    }

    return ret;
}

long long modInverse(long long base)
{
    return bigMod(base, mod - 2);
}
