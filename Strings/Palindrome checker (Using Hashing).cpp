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
const int N = 1e6+9, mod = 1e9+9;


const int mod1 = 999999937, mod2 = 1e9 + 223;
const int base1 = 137, base2 = 149;

pair< int,int >pw[N];
void pre()
{
    pw[0] = {1,1}; // any base ^ 0 = 1;
    for(int i=1; i<N; i++)
    {
        pw[i].ff = 1LL * pw[i-1].ff * base1 % mod1;
        pw[i].sc = 1LL * pw[i-1].sc * base2 % mod2;
    }
}

struct Hashing
{
    int n;
    string s; /// 0-indexed
    vector<pair<int,int>> pre_hs,suf_hs; /// 1-indexed
    Hashing() {}
    Hashing(string _s)
    {
        n = _s.size();
        s = _s;
        pre_hs.pb({0,0});
        for(int i=0; i<n; i++)
        {
            pair<int,int> p;
            p.ff = ((1LL*pre_hs[i].ff*base1) + s[i] % mod1) % mod1;
            p.sc = ((1LL*pre_hs[i].sc*base2) + s[i] % mod2) % mod2;
            pre_hs.pb(p);
        }
        suf_hs.pb({0,0});
        for(int i=n-1; i>=0; i--)
        {
            pair<int,int> p;
            p.ff = ((1LL*suf_hs.back().ff*base1) + s[i] % mod1) % mod1;
            p.sc = ((1LL*suf_hs.back().sc*base2) + s[i] % mod2) % mod2;
            suf_hs.pb(p);
        }
        suf_hs.pb({0,0});
        reverse(all(suf_hs));
    }
    pair<int,int> get_prefix_hash(int l,int r)
    {
        assert(l >= 1 && l <= r && r <= n);
        pair<int,int> ans;
        ans.ff = ((pre_hs[r].ff - (1LL*pre_hs[l-1].ff*pw[r-l+1].ff) % mod1) % mod1 + mod1) % mod1;
        ans.sc = ((pre_hs[r].sc - (1LL*pre_hs[l-1].sc*pw[r-l+1].sc) % mod2) % mod2 + mod2) % mod2;
        return ans;
    }

    pair<int,int> get_suffix_hash(int l,int r)
    {
        assert(l >= 1 && l <= r && r <= n);
        pair<int,int> ans;
        ans.ff = ((suf_hs[l].ff - (1LL*suf_hs[r+1].ff*pw[r-l+1].ff) % mod1) % mod1 + mod1) % mod1;
        ans.sc = ((suf_hs[l].sc - (1LL*suf_hs[r+1].sc*pw[r-l+1].sc) % mod2) % mod2 + mod2) % mod2;
        return ans;
    }
    bool Is_pal(int l,int r)
    {
        if(l == r)return 1;
        int a = l;
        int b = l + (r-l+1)/2 - 1;
        int x = l + (r-l+1)/2;
        if((r-l+1) & 1) x++;
        int y = r;
        return get_prefix_hash(a,b) == get_suffix_hash(x,y);
    }
};



int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
//    srand(time(NULL));

    pre();
    string s;
    cin >> s;
    Hashing H(s);
    if(H.Is_pal(1,s.size()))
        puts("Palindrome");
    else
        puts("No");

}
