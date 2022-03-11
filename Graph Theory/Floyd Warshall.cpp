//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define yes         cout<<"YES"<<endl;
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
const int N=1e5+9,mod=1e9+7;

int n,m;
vector< vector<int> > G;
void print()
{
    cout << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(G[i][j] == inf) cout << "inf  ";
            else cout<<G[i][j]<< "  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);

    cin>>n>>m;

    G.assign(n+200,vector<int>(n+200,inf));

    for(int i=0; i<m; i++)
    {
        int x,y,c;
        scc(x)
        scc(y)
        scc(c)
        G[x][y] = c;
    }

//    for(int i=1;i<=n;i++) G[i][i] = 0;
    print();

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(G[i][j] > G[i][k] + G[k][j])
                {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
        print();
    }


    puts("Final : ");
    print();


    return 0;
}

/*
4 6
2 1 2
1 2 3
3 2 5
2 3 2
4 3 8
4 1 20
*/
