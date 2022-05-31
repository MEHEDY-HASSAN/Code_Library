//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define yes         puts("Yes");
#define no          puts("No");
#define ff          first
#define sc          second
#define inf         999999999
#define pi          3.14159265358979323846264
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
const int N = 1e5+9, mod = 1e9+9;

int a[N];
int n,m;

/// Find how many numbers are in the range [l,r] strictly less than K
/// Merge Sort Tree

struct ST
{
    #define lc (node<<1)
    #define rc ((node<<1) | 1)
    vector<long long>v[4*N];

    void build(int node,int l,int r)
    {
        if(l == r)
        {
            v[node].push_back(a[l]);
            return;
        }
        int mid = (l+r)>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        merge(all(v[lc]),all(v[rc]),back_inserter(v[node]));
    }
    long long query(int node,int l,int r,int i,int j,int k)
    {
        if(l > j || r < i) return 0;
        if(l >= i && r <= j)
            return lower_bound(all(v[node]),k) - v[node].begin();
        return query(lc,l,l+r>>1,i,j,k) + query(rc,(l+r>>1)+1,r,i,j,k);
    }
}t;

void Solve(int _)
{
    scc(n)
    scc(m)
    for(int i=1; i<=n; i++)
    {
        scc(a[i])
    }
    t.build(1,1,n);

    while(m--)
    {
        int l,r,k;
        scc(l)
        scc(r)
        scc(k)
        cout << t.query(1,1,n,l,r,k) << '\n';
    }

}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
//    srand(time(NULL));

    int _ = 1,__ = 0;
//    scc(_)
    while(++__ <= _)
        Solve(__);

    return 0;
}

