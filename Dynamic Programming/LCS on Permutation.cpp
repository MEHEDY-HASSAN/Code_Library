
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
const int N=2e5+9,mod=1e9+7;


int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);

    int n;
    scc(n)
    vector<int> a(n+10),b(n+10),dp(n+10,inf);

    for(int i=1,x;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1,x;i<=n;i++)
    {
        scc(x)
        b[x] = i;
    }

    int ans = 1;
    for(int i=1;i<=n;i++)
    {
        int i1 = i;
        int i2 = b[a[i]];
        int len = upper_bound(dp.begin()+1,dp.end(),i2) - dp.begin();
        dp[len] = min(dp[len],i2);

        ans = max(ans,len);
    }

    cout<< ans;
    return 0;
}
/*
5
3 2 1 4 5
1 3 4 5 2

Result = 3;
*/
