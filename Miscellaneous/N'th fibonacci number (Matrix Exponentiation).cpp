
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define yes         puts("Yes");
#define no          puts("No");
#define ff          first
#define sc          second
#define inf         999999999
#define pi          3.14159265358979323846264
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
const int N = 1e6+9, mod = 1e9+7;


void multiply(ll F[2][2], ll M[2][2]) {
   ll a = (F[0][0] * M[0][0])%mod + (F[0][1] * M[1][0])%mod;
   ll b = (F[0][0] * M[0][1])%mod + (F[0][1] * M[1][1])%mod;
   ll c = (F[1][0] * M[0][0])%mod + (F[1][1] * M[1][0])%mod;
   ll d = (F[1][0] * M[0][1])%mod + (F[1][1] * M[1][1])%mod;
   F[0][0] = a%mod;
   F[0][1] = b%mod;
   F[1][0] = c%mod;
   F[1][1] = d%mod;
}

void Power(ll F[2][2], ll n) {
   if (n == 0 || n == 1)
      return;
   ll M[2][2] = {{1,1},{1,0}};
   Power(F, n / 2);
   multiply(F, F);
   if (n % 2 != 0)
      multiply(F, M);
}
ll Fibonacci(ll n) {
   ll F[2][2] = {{1,1},{1,0}};
   if (n == 0)
      return 0;
   Power(F, n - 1);
   return F[0][0] % mod;
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
//    srand(time(NULL));

    ll n;
    while(cin >> n)
    {
        cout << Fibonacci(n) << '\n';
    }

    return 0;
}

