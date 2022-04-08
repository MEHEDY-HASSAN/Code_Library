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
vector<int>v[N],r[N],components;
vector< vector<int> >ALLComponents;
stack<int>order;
bool vis[N];
int timer = 1;

void DFS(int u)
{
    vis[u] = 1;
    for(auto x:v[u])
    {
        if(!vis[x]) DFS(x);
    }
    order.push(u);
}

void dfs(int u)
{
    vis[u] = 1;
    components.pb(u);
    for(auto x:r[u])
    {
        if(!vis[x]) dfs(x);
    }
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);


    scc(n)
    scc(m)

    for(int i=0,a,b; i<m; i++)
    {
        scc(a)
        scc(b)
        v[a].pb(b);
        r[b].pb(a);
    }

    for(int i=1; i<=n; i++) if(!vis[i]) DFS(i);
    for(int i=1; i<=n; i++) vis[i] = false;

    while(!order.empty())
    {
        if(!vis[order.top()])
        dfs(order.top());

        if(!components.empty())
        ALLComponents.pb(components);

        components.clear();
        order.pop();
    }

    for(auto x:ALLComponents)
    {
        printv(x)
        puts("");
    }

    return 0;
}
/*
7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5

1 3 2

4

5 7 6
*/
