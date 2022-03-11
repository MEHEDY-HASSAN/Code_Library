
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
#define inf     999999999
#define pi      3.14159265359
inline  int     random(int a=1,int b=10){return a+rand()%(b-a+1);}
typedef long long ll;
typedef pair<ll,ll> pii;
const int N=209;
int n,e;
vector<int>v[N];
bitset<209>vis;
bitset<209>color;
bool dfs(int node,int c)
{
    vis[node]=1;
    color[node]=c;

    for(auto child:v[node])
    {
        if(!vis[child])
        {
            if(dfs(child,1-c)==false)
                return false;
        }
        else
            if(color[node]==color[child])return false;
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    while(cin>>n)
    {
        if(n==0)exit(0);
        cin>>e;

        vis.reset();
        color.reset();

        int i,j,x,y;
        for(i=0;i<e;i++)
        {
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }


        puts(dfs(1,0) ? "BICOLORABLE.":"NOT BICOLORABLE.");

//        for(i=0;i<n;i++)see(color[i])
        for(i=0;i<=n;i++)
            v[i].clear();
    }

    return 0;
}

