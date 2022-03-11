long long mulmod(long long a,long long b,long long m)
{
    long long res = 0;
    a %= m;
    while(b)
    {
        if(b&1LL)
        {
            res = (res + a)%m;
        }
        a = (a+a)%m;
        b >>= 1;
    }
    return res;
}

// (a * b) % m
