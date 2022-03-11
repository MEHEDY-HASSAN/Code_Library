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
const int N=100009;
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

int id[N],node,edge,sz[N];
vector< pair < int , pair<int,int> > > adj;
int root(int a)
{
    if(a==id[a])return a;
    return id[a]=root(id[a]);
}

bool cycle(pair<int,int>p)
{
    return root(p.ff)==root(p.sc);
}

void unionn(pair<int,int> p)
{
    int a=root(p.ff);
    int b=root(p.sc);
    if(a==b)return ;

    if(sz[a]>sz[b])swap(a,b);

    id[a]=b;
    sz[b]+=sz[a];
}

int mst()
{
    int i,j,ans=0;

    for(i=1;i<=node;i++)id[i]=i,sz[i]=1;

    sort(all(adj));

    for(auto p : adj)
    {
        if(!cycle(p.sc))
        {
            int cost = p.ff;
            int A = p.sc.ff;
            int B = p.sc.sc;
            see(cost,A,B)
            ans+=p.ff;
            unionn(p.sc);
        }
    }
    return ans;
}

int main()
{
    int i,u,v,w;
    cin>>node>>edge;

    for(i=0;i<edge;i++)
    {
        cin>>w>>u>>v;
        adj.pb({w,{u,v}});
    }

    cout<<mst()<<endl;
    return 0;
}

