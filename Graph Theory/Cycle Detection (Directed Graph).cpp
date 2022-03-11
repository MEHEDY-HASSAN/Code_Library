#include<bits/stdc++.h>

using namespace std;

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

vector<int>adj[100];
bool vis[100];
bool pending[100];

int nodes,edges;

bool dfs(int i)
{
    vis[i] = 1;

    pending[i] = 1;

    for(auto x:adj[i])
    {
        if(!vis[x])
        {
            if(dfs(x)) return 1; // cycle
        }
        else
        {
            if(pending[x]) return 1; // cycle
        }
    }

    pending[i] = 0;

    return 0; // no cycle
}

int main()
{
    cin>>nodes>>edges;

    for(int i=0,a,b;i<edges;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    bool cycle = 0;

    for(int i=1;i<=nodes;i++)
    {
        if(!vis[i])
        {
            cycle = cycle | dfs(i);
        }
    }

    if(cycle)
    {
        cout<< "Cycle detected";
    }
    else
    { 
        cout<< "There is no cycle";
    }

    return 0;
}
