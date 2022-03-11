/*
The Edmonds-Karp algorithm is an implementation of the Ford-Fulkerson method for computing a maximal flow in a flow network
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define ya          cout<<"YES"<<endl;
#define no          cout<<"NO"<<endl;
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
const int N=509,mod=998244353;

int nodes,edges;
vector<int> adj[N];
int capacity[N][N];

int bfs(int s,int t,vector<int> &parent)
{
    fill(parent.begin(),parent.begin()+nodes+2,-1);
    parent[s] = -2;
    queue< pair<int,int> >q; /// node, min flow
    q.push({s,INT_MAX});

    while(!q.empty())
    {
        int cur = q.front().ff;
        int flow = q.front().sc;
        q.pop();

        for(auto next : adj[cur])
        {
            if(parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow,capacity[cur][next]);
                if(next == t)
                    return new_flow;
                q.push({next,new_flow});
            }
        }
    }

    return 0;
}

int max_flow(int s,int t)
{
    int ans = 0;
    vector<int>parent(nodes+3);
    int new_flow;
    while(new_flow = bfs(s,t,parent)) /// while there is a path
    {
        ans += new_flow;
        int cur = t;
        while(cur!=s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return ans;
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);

    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb(b);
        adj[b].pb(a);
        capacity[a][b] = c;
    }

    int s,t; /// source and sink
    cin>>s>>t;
    cout<<max_flow(s,t);

    return 0;
}

/*
6 9
1 2 7
1 5 4
5 2 3
5 4 2
2 4 3
2 3 5
4 3 3
4 6 5
3 6 8
1 6
ans 10

6 7
1 2 2
1 3 5
3 4 3
2 4 3
2 5 1
5 6 4
4 6 4
1 6
ans 5
*/
