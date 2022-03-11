//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb      push_back
#define all(v)  v.begin(),v.end()
#define see(x)  cout<<#x<<" : "<<(x)<<endl;
#define ya      cout<<"YES"<<endl;
#define no      cout<<"NO"<<endl;
#define ff      first
#define sc      second
#define scc(a)  scanf("%lld",&a);
#define inf     999999999
inline  int     random(int a=1,int b=20){return a+rand()%(b-a+1);}
typedef long long ll;
typedef pair<ll,ll> pii;

const int mod=1000003,N=1000009;

ll fact[N];

void factorial()
{
    fact[0]=1;
    fact[1]=1;

    for(int i=2;i<N;i++)
        fact[i] = (i * fact[i-1])%mod;
}
ll bigmod(ll b,ll p) /// (b^p) % mod
{
    if(p==0) return 1;
    ll ret = bigmod(b,p/2);
    ret = (ret*ret) % mod;
    if( p&1 ) return (ret*b) % mod;
    return ret;
}
ll nCr(ll n,ll r)
{
    ll ans = fact[n] % mod;
    ans = ( ans * bigmod(fact[r],mod-2) ) % mod;
    ans = ( ans * bigmod(fact[n-r],mod-2) ) % mod;
    return ans;
}

//ll nCr(ll n , ll r) { // Without any Precompute
//
//    if(n<r)return 0;
//    if(n==r)return 1;
//
//    ll ans=1;
//    for(ll k=n,p=1;k>(n-r);k--)
//    {
//        ans *= k;
//        if(p<=r)
//        {
//            ans/=p;
//            p++;
//        }
//    }
//    return ans;
//}

//ll nPr(ll n,ll r) // without any Precompute
//{
//
//    if(n<r)return 0;
//    ll ans = 1;
//    while(r--)
//    {
//        ans *= n;
//        n--;
//    }
//    return ans;
//}

int main()
{
    factorial();

    int _;
    cin>>_;
    for(int i=1;i<=_;i++)
    {
        ll n,r;
        scc(n)
        scc(r)
        printf("Case %d: %lld\n",i,nCr(n,r));
    }

    return 0;
}
