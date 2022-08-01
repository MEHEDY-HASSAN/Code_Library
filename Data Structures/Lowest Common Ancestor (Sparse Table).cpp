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
using ll = long long;
inline ll           lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
#define see(x)  cout<<endl<<#x<<" : "<<(x)<<endl;
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

using pll =  pair<ll,ll>;
using pii = pair<int,int>;
const int N = 1e5+9, mod = 1e9+9;
const int LOG = 22;

vector<int>v[N];
int p[N][27];
int level[N];
int n,m;

void Dfs(int x,int f=-1)
{
    p[x][0] = f;
    for(int j=1; j<=LOG; j++)   if(p[x][j-1] != -1) p[x][j] = p[p[x][j-1]][j-1];
    for(auto i:v[x])
    {
        if(f == i) continue;
        level[i] = level[x] + 1;
        Dfs(i,x);
    }
}
int LCA(int a,int b)
{
    if(level[a] > level[b]) swap(a,b);
    for(int i=LOG; i>=0; i--)
        if(level[b] - (1LL<<i) >= level[a])
            b = p[b][i];
    if(a == b) return a;

    for(int i=LOG; i>=0; i--)
        if(p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
    return p[a][0];
}
int kth(int u, int k) // 0'th is u itself
{
  assert(k >= 0);
  for (int i = 0; i <= LOG; i++) if (k & (1 << i)) u = p[u][i];
  return u;
}
int Dist(int a,int b)
{
    return level[a] + level[b] - (2*level[LCA(a,b)]);
}
int kthFrom_U_to_V(int u,int v,int k)
{
    int lca = LCA(u,v);
    int d = Dist(u,v);
    assert(k <= d);
    if(level[lca] + k <= level[u]) return kth(u,k);
    k -= level[u] - level[lca];
    return kth(v, level[v] - level[lca] - k);
}

void Solve(int _)
{

    scc(n)
    vector<int>t(n+1);
    for(int i=1,d,x; i<=n; i++)
    {
        scc(d)
        while(d--)
        {
            scc(x)
            t[x]++;
            v[i].pb(x);
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(t[i] == 0)
        {
            Dfs(i);
            break;
        }
    }

    scc(m)

    printf("Case %d:\n",_);
    for(int a,b; m--;)
    {
        scc(a)
        scc(b)
        cout << kth(a,b) << '\n';
    }

    scc(m)
    while(m--)
    {
        int a,b,k;
        scc(a)
        scc(b)
        scc(k)
        cout << kthFrom_U_to_V(a,b,k) << endl;
    }

    for(int i=0; i<=n; i++) v[i].clear(),level[i] = 0;
    for(int i=0; i<=n; i++)
        for(int j=0; (1<<j)<=n; j++)
            p[i][j] = -1;

}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
//    srand(time(NULL));

    int _ = 1,__ = 0;
    scc(_)
    while(++__ <= _)
        Solve(__);

    return 0;
}
/// SPOJ : https://www.spoj.com/problems/QTREE2/cstart=10
/// SPOJ : https://www.spoj.com/problems/LCA/cstart=80
/*
10
2 2 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
0
0
1
8 9
*/
