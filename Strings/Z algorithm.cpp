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
const int N = 3e6+9, mod = 1e9+9;

int Z[N]; /// Each element of the Z-array consists of the length of the longest substring
        /// of the string starting from i which can be used as a prefix of the string itself.
        /// String - a b a c a b a
        ///          0 0 1 0 3 0 1
void CreateZarray(string str)
{
   int n = str.size();
   int L, R, k;
   L = R = 0;
   for (int i = 1; i < n; ++i){
      if (i > R){
         L = R = i;
         while (R<n && str[R-L] == str[R])
         R++;
         Z[i] = R-L;
         R--;
      } else {
         k = i-L;
         if (Z[k] < R-i+1)
            Z[i] = Z[k];
         else {
            L = i;
            while (R<n && str[R-L] == str[R])
               R++;
            Z[i] = R-L;
            R--;
         }
      }
   }
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
//    srand(time(NULL));


    string a,b;
    cin >> a >> b;
    CreateZarray(a);
    for(int i=0; i<a.size(); i++)
        cout << Z[i] << ' ';

    return 0;
}

