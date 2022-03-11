/*
A modular multiplicative inverse of an integer a is an integer x such that the product ax is congruent to 1 with respect to the modulus m
*/


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
const int N=2e5+9,mod=1e9+7;

int gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return 1;
    }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);

    /// we want to find (1/a) mod  m
    /// if x = (1/a) mod m then a * x = 1 mod m
    /// condition: GCD(a,m) must be 1
    /// Extended Euclidean algorithm a x + m y = 1 here x is our answer

    int x,y,a,m;
    cin>>a>>m;
    int g = gcd(a,m,x,y);

    if(g != 1)
    {
        puts("Not exists");
    }
    else
    {
        x = (x % m + m) % m;
        cout<< x;
    }

    return 0;
}
