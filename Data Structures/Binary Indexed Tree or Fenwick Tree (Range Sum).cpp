#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

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
#define scc(a)  scanf("%d",&a);
#define inf     999999999
inline  int     random(int a=1,int b=10){return a+rand()%(b-a+1);}
typedef long long ll;
typedef pair<ll,ll> pii;
const int N=1e5+9;
ll n,q;
vector<ll>v;
ll tree[N];
ll query(ll i)
{
    ll res=0;
    while(i>0)
    {
        res += tree[i];
        i -= i & (-i);
    }
    return res;
}
void update(ll i,ll x)
{
    while(i<=N)
    {
        tree[i]+=x;
        i += i & (-i);
    }
}

int main()
{
    int _;
    cin>>_;
    while(_--){
    memset(tree,0,sizeof tree);

    cin>>n>>q;

    ll i,j,k,a,b=0,ans=0;

    v.assign(n,0);

    for(i=0;i<n;i++)
    {
        cin>>v[i];
        update(i+1,v[i]);
    }

    while(q--)
    {
        cin>>a>>b;
        cout<<query(b)-query(a-1);
        puts("");
    }

    }
    return 0;
}
