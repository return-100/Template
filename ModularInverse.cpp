long long modPower(long long a, long long b)
{
    long long ret = 1;
    
    while (b)
    {
        if (b & 1)
            ret *= a, ret %= mod;
        
        a *= a, a %= mod;
        b >>= 1;
    }
    
    return ret;
}

long long modInverse(long long a)
{
    return modPower(a, mod - 2);
}
