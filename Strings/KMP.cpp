
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define ya          cout<<"YES"<<endl;
#define no          cout<<"NO"<<endl;
#define ff          first
#define sc          second
#define inf         999999999
#define pi          3.14159265359
#define printv(v)   for(auto x:v)cout<<x<<' ';cout<<endl;
#define takev(v)    for(auto &x:v)cin>>x;
inline  int         random(int a=1,int b=10){return a+rand()%(b-a+1);}

//#define see(x)  cout<<endl<<#x<<" : "<<(x)<<endl;
#define see(args...) \
{ \
    string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
    stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);\
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr<< *it << " = " << a <<",\n"[++it==istream_iterator<string>()];
	err(it, args...);
}

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int N=2e5+9;

int naive(string s,string pat)
{
    for(int i=0;i<s.size();i++)
    {
        bool ok=1;
        for(int j=0;j<pat.size();j++)
        {
            if(i+j<s.size() && s[i+j]!=pat[j])ok=0;
        }
        //see(s[i])
        if(ok)return i;
    }
    return -1;
}

int prefixlen[N];
void calculate_pre(string pat)
{
    int n = pat.size();
    prefixlen[0] = -1;
    prefixlen[1] = 0;
    int len=0;
    int i=1;
    while(i < n)
    {
        if(pat[len]==pat[i]) /// match
        {
            len++;
            i++;
            prefixlen[i]=len;
        }
        else if(len > 0) /// miss match and len >0
        {
            len = prefixlen[len]; /// note that we do not increase i here
        }
        else /// miss match and len = 0
        {
            i++;
            prefixlen[i]=0; /// len reached 0 , so save that into prefixlen array and move forward
        }
    }
}
vector<int> KMP(string txt,string pat)
{
    calculate_pre(pat);
    int t=0;
    int p=0;
    int n=txt.size();
    int m=pat.size();
    vector<int>match;
    while(t<n)
    {
        if(txt[t]==pat[p])
        {
            p++;
            t++;
            if(p == m)
            {
                /// occurrence found , if only first occurrence is needed then we can return here
                match.pb(t-p);
                p = prefixlen[p]; /// reset
            }
        }
        else
        {
            p = prefixlen[p]; /// key line
            if(p<0)
            {
                t++;
                p++;
            }
        }
    }
    return match;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s,pat;
    cin>>s;
    ///vector<int>v=KMP(s,pat);
    calculate_pre(s);
    for(int i=1;i<=s.size();i++)
        cout<<prefixlen[i]<<' ';
    cout<<endl;
    ///printv(v);

    return 0;
}
