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
typedef long long ll;
typedef pair<ll,ll> pii;
const int N=100009;
int id[N]={0,1,1,3,3,5,1,3,3},n,q;
int sz[N];
/// avoid tall trees
/// keep track of number of objects each time
/// link root of smaller tree to root of larger tree

//int root(int i)
//{
//    while(i!=id[i])
//    {
//        id[i]=id[id[i]];
//        i=id[i];
//    }
//    return i;
//}

int root(int t)
{
    if(t==id[t])return t;
    return id[t]=root(id[t]);
}

void unionn(int a,int b)
{
    int i=root(a);
    int j=root(b);
    see(root(a))
    see(root(b))
    ///id[f]=t;
    if(i==j)return ;
    if(sz[i]<sz[j])
    {
        id[i]=j;
        sz[j]+=sz[i];
    }
    else
    {
        id[j]=i;
        sz[i]+=sz[j];
    }
}

bool connceted(int a,int b)
{
    return root(a)==root(b);
}

int main()
{
    int i,j,t,a,b;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        id[i]=i;
    }
    fill(sz+1,sz+n+1,1);

    cin>>q;

    while(q--)
    {
        cin>>t>>a>>b;
        if(t==1)
        {
            if(connceted(a,b))
                ya
            else no
        }
        else
        {
            unionn(a,b);
        }
        for(i=1;i<=n;i++)
        {
            cout<<sz[i]<<' '<<id[i]<<endl;
        }
        cout<<endl;
    }

    return 0;
}

