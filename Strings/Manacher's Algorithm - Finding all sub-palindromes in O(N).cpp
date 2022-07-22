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
/// https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/
vector<int> PLen(N<<1);
// PLen[i] is the Max Palindrome len if the center is ConvertedString[i].
// Manacher's Algorithm
pair<int,int> Manacher(string s){
    /*
        If length of given string is n then its length after
        inserting n+1 "#", one "@", and one "$" will be
        (n) + (n+1) + (1) + (1) = 2n+3
    */
    int strLen = 2 * s.size() + 3;
    char* sChars = new char[strLen];
    /*
        Inserting special characters to ignore special cases
        at the beginning and end of the array
        "abc" -> @ # a # b # c # $
        "" -> @#$
        "a" -> @ # a # $
    */
    sChars[0] = '@';
    sChars[strLen - 1] = '$';
    int t = 1;

    for (char c : s){
        sChars[t++] = '#';
        sChars[t++] = c;
    }
    sChars[t] = '#';

    int maxLen = 0;
    int start = 0;
    int maxRight = 0;
    int center = 0;

    for(int i = 1; i < strLen - 1; i++){
        if (i < maxRight){
            PLen[i] = min(maxRight - i, PLen[2 * center - i]);
        }
        // Expanding along the center
        while (sChars[i + PLen[i] + 1] == sChars[i - PLen[i] - 1]){
            PLen[i]++;
        }
        // Updating center and its bound
        if (i + PLen[i] > maxRight){
            center = i;
            maxRight = i + PLen[i];
        }
        // Updating ans
        if (PLen[i] > maxLen){
            start = (i - PLen[i] - 1) / 2;
            maxLen = PLen[i];
        }
    }
    return {start,maxLen};
}

string GetLPS(string s) // Longest Palindromic Substring
{
    pair<int,int> x = Manacher(s);
    string res;
    for (int i = x.ff; i <= x.ff+x.sc-1; i++)
        res += s[i];
    return res;
}

void Solve(int _)
{
    string s;
    cin >> s;
    cout << GetLPS(s);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
//    srand(time(NULL));

    int _ = 1,__ = 0;
//    scc(_)
    while(++__ <= _)
        Solve(__);

    return 0;
}
