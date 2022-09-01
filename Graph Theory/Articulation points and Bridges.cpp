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
const int N=1e6+9,mod=998244353;

int n,m;
vector<int>v[N],Low(N,-1),dis(N,-1);
bool vis[N];
int AP[N];
/// Low[] কত উপরে একটা নোডের সাথে connected. (using Back-edge with i or subtree of i)
///dis[] discovery time
int timer = 0;
vector< pii > res;
void dfs(int u,int F = -1)
{
    vis[u] = 1;
    dis[u] = timer;
    Low[u] = timer;
    ++timer;
    int child = 0;
    for(auto x:v[u])
    {
        if(F == x) continue;
        if(!vis[x])
        {
            child++;
            dfs(x,u);
            Low[u] = min(Low[x],Low[u]);
            if(F != - 1 && Low[x] >= dis[u]) AP[u] = 1;
            if(Low[x] > dis[u])
                res.pb({min(x,u),max(x,u)}); /// If bidirectional graph.else push(u,v).
        }
        else
        {
            Low[u] = min(Low[u],dis[x]);
        }
    }
    if(child > 1 && F == -1) AP[u] = 1;
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);


    scc(n)
    scc(m)

    for(int i=0,a,b;i<m;i++)
    {
        scc(a)
        scc(b)
        v[a].pb(b);
        v[b].pb(a);
    }

    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);

    puts("");
    for(int i=1;i<=n;i++)
    {
        cout << i << " : " << AP[i] << '\n';
    }

    /**
        Important tips:
        *  2 edge connected components: no bridge in graph
        *  if there are bridge SCC is not possible
    */

    return 0;
}
/*
// Directed
5 5
1 2
2 3
3 4
4 2
4 5

2

// Undirected
11 12
1 2
1 8
8 9
9 10
9 11
10 11
2 3
3 7
3 4
4 6
6 7
5 4

6

// 0 indexed
6 7
0 5
0 1
1 3
3 4
4 2
2 3
2 1


*/
