
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
typedef long long ll;
typedef pair<ll,ll> pii;
const ll N=1e6+7;
vector<ll>prime;
bool vis[N];
void sieve()
{
    ll i,j;
    for(i=4; i<N; i+=2)vis[i]=1;
    for(j=3; j*j<=N; j++)
    {
        if(!vis[j])
        {
            for(i=2*j; i<N; i+=j)
                if(!vis[i])
                    vis[i]=1;
        }
    }
    for(i=2; i<N; i++)
        if(!vis[i])
            prime.pb(i);
}
map<ll,ll> factorize(ll n)
{
    map<ll,ll>m;
    ll nn=n;
    for(ll i=0; prime[i]*prime[i]<=n; i++)
    {
        while(n%prime[i]==0)
        {
            n/=prime[i];
            m[prime[i]]++;
        }
        if(n==1)break;
    }
    if(n!=1)
    {
        m[n]=1;
    }
    return m;
}

int main()
{
    sieve();

    ll n,i,j=24;
    while(cin>>n)
    {
        map<ll,ll>m=factorize(n);
        for(auto [l,r]:m)
        {
            cout<<l<<' '<<r<<endl;
        }
    }
    return 0;
}

