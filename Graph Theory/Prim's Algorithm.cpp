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
#define inf     999999999

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

typedef long long ll;
typedef pair<ll,ll> pii;
const int N=2e5+9;
/*
8 11
2 1 5
4 1 2
10 1 4
5 4 5
8 2 4
18 2 3
11 3 4
11 4 7
9 4 8
2 8 6
1 7 6
ans is 34

7 11
7 1 2
5 1 4
9 2 4
8 2 3
7 2 5
5 3 5
15 4 5
6 4 6
8 5 6
9 5 7
11 6 7
ans 39
*/

bool taken[N];
int node,edge;
vector< pair<int,int> > adj[N];
priority_queue< pair<int,pii> >q;

void go(int x)
{
    taken[x]=1;
    for(auto [node,weight]:adj[x])
    {
        if(!taken[node])
        {
            q.push({-weight,{node,x}});
        }
    }
}

int mst()
{
    int ans=0;

    go(1);

    while(!q.empty())
    {
        int weight = -q.top().ff;
        int B = q.top().sc.ff;
        int A = q.top().sc.sc;

        q.pop();

        if(!taken[B])
        {
            ans += weight;
            see(weight,A,B)
        }

        go(B);
    }

    return ans;
}

int main()
{
    int i,u,v,w;
    cin>>node>>edge;

    for(i=0;i<edge;i++)
    {
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    cout<<mst()<<endl;

    return 0;
}

