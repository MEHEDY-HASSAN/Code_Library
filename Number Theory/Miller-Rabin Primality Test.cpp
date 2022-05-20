
// https://www.spoj.com/problems/PON/

#include<bits/stdc++.h>
#include<string.h>

using namespace std;

typedef long long ll;

#define scc(n) scanf("%d",&n);
#define sccc(n) scanf("%lld",&n);

//mt19937 rd(time(0));
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll mulmod(ll a,ll b,ll m)
{
    ll res = 0;
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

ll bigmod(ll b,ll p,ll m)
{
    b=b%m;
    if(p==0)
        return 1;
    ll ans = bigmod(b,p/2,m);
    ans = mulmod(ans,ans,m);
    if(p & 1)
        return mulmod(ans,b,m);
    else
        return ans;

}

bool check_composite(ll d,ll n)
{
    ll a = uniform_int_distribution<ll>(2LL,n-2)(rng);
    /// a ^ (n-1) = 1 mod n if we assume n is a prime
    ll x = bigmod(a,d,n);
    if(x == 1 || x == n-1) return 1;

    while(d != n-1)
    {
        x = mulmod(x,x,n);
        d *= 2;
        if(x == 1) return 0;
        if(x == n-1) return 1;
    }
    return 0;
}
bool MillerTEST(ll n)
{
    if(n==2 || n==3)return 1;
    if(n<=4) return 0;

    ll d = n - 1;
    while(d%2 == 0) d /= 2;

    for(int i=1;i<=5;i++){
        if( !check_composite(d,n) ) return false;
    }
    return true;
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);

    int _; // number of test cases.
    scc(_)

    while(_--)
    {
        ll n;
        sccc(n);

        if(MillerTEST(n))printf("YES\n");
            else printf("NO\n");

    }
    return 0;
}
