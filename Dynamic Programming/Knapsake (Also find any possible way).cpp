
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define yes         cout<<"Yes"<<endl;
#define no          cout<<"No"<<endl;
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

int n,x;
vector< vector<int> >dp;

void print()
{
    puts("");
    cout<< "  ";
    for(int j=0;j<=x;j++) cout << j << "  ";
    puts("");
    for(int i=0;i<=n;i++)
    {
        cout<< i << ' ';
        for(int j=0;j<=x;j++)
        {
            cout<< dp[i][j] << "  " ;
        }
        cout<<endl;
    }
    puts("");
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);

    scc(n)
    scc(x) // max cost

    vector<int> h(n+2),s(n+2);
    for(int i=1;i<=n;i++) scc(h[i]) // cost

    for(int i=1;i<=n;i++) scc(s[i]) // profit

    dp.assign(n+10,vector<int>(x+10,0));

    for(int i=1;i<=n;i++)
    {
        for(int cost=0;cost<=x;cost++)
        {
            if(cost - h[i] >= 0)
            dp[i][cost] = max(dp[i-1][cost-h[i]]+s[i],dp[i-1][cost]);
            else
            dp[i][cost] = dp[i-1][cost];
        }
        print();
        cout<< endl;
    }

    cout<< dp[n][x] <<endl;

    bitset < 1009 > taken;
    taken.reset();

    int i = n , j = x;
    while(i>0 && j>0)
    {
        if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else
        {
            taken[i] = 1;
            j -= h[i];
            i--;
        }
    }

    for(int i=1;i<=n;i++)see(i,taken[i],h[i],s[i])

    return 0;
}
/*

4 10
4 8 5 3
5 12 8 1

3 50
10 20 30
60 100 120

*/
