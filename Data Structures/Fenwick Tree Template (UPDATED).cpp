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
const int N = 2e5+9, mod = 1e9+9;

struct Fenwick {
    int n;
    vector<ll> tree;
    Fenwick(int _N)
    {
        n = _N;
        tree.resize(_N + 1,0);
    }
    void update(ll i,ll val)
    {
        while(i<=n)
        {
            tree[i] += val;
            i += i & (-i);
        }
    }
    ll Query(ll i)
    {
        ll res=0;
        while(i>0)
        {
            res += tree[i];
            i -= i & (-i);
        }
        return res;
    }
    ll query(int l, int r){
        if(l > r) swap(l, r);
        ll ret = Query(r);
        if(l>0)ret -= Query(l-1);
        return ret;
    }
};

void Solve(int _)
{



}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
//    srand(time(NULL));


    int _ = 1,__ = 0;
//    scc(_)
    while(++__ <= _) Solve(__);

    return 0;
}
