//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define yes         puts("YES");
#define no          puts("NO");
#define ff          first
#define sc          second
#define inf         999999999
#define pi          3.14159265359
#define printv(v)   for(auto x:v)cout<<x<<' ';cout<<endl;
#define takev(v)    for(auto &x:v)cin>>x;
inline  int         random(int a=1,int b=10)
{
    return a+rand()%(b-a+1);
}
typedef long long ll;
inline ll           lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
//#define see(x)  cout<<endl<<#x<<" : "<<(x)<<endl;
#define see(args...) \
{ \
    string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
    stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);\
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout<< *it << " = " << a <<",\n"[++it==istream_iterator<string>()];
    err(it, args...);
}
#define scc(n) scanf("%d",&n);
#define sccc(n) scanf("%lld",&n);

typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int N=5e5+9,mod=1e9+7;

int a[N];
struct ST
{
    #define lc (node<<1)
    #define rc ((node<<1) | 1)
    long long t[4*N],lazy[4*N];
    ST()
    {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    inline void push(int node,int l,int r)
    {
        if(lazy[node] == 0)return;
        t[node] = t[node] + lazy[node] * (r-l+1);
        if(l != r)
        {
            lazy[lc] = lazy[lc] + lazy[node];
            lazy[rc] = lazy[rc] + lazy[node];
        }
        lazy[node] = 0;
    }
    inline long long Merge(long long a,long long b)
    {
        return a+b;
    }
    inline void pull(int node)
    {
        t[node] = t[lc] + t[rc];
    }
    void build(int node,int l,int r)
    {
        lazy[node] = 0;
        if(l == r)
        {
            t[node] = a[l];
            return;
        }
        int mid = (l+r)>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        pull(node);
    }
    void update(int node,int l,int r,int i,int j,long long v)
    {
        push(node,l,r);
        if(j < l || r < i) return;
        if(i <= l && r <= j)
        {
            lazy[node] = v;
            push(node,l,r);
            return;
        }
        int mid = (l+r)>>1;
        update(lc,l,mid,i,j,v);
        update(rc,mid+1,r,i,j,v);
        pull(node);
    }
    long long query(int node,int l,int r,int i,int j)
    {
        push(node,l,r);
        if(i > r || l > j) return 0;
        if(i <= l && r <= j) return t[node];
        int mid = (l+r)>>1;
        return Merge(query(lc,l,mid,i,j),query(rc,mid+1,r,i,j));
    }
}t;

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);


    return 0;
}

