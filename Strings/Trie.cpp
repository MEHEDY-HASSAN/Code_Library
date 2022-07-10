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
const int N = 4e5+9, mod = 1e9+9;

struct Trie{
    static const int B = 30;
    struct node{
        node *nxt[2];
        int sz;
        node(){
            nxt[0] = nxt[1] = NULL;
            sz = 0;
        }
    }*root;
    Trie(){
        root = new node();
    }
    void Insert(int x){
        node* cur = root;
        cur -> sz++;
        for(int i=B; i>=0; i--)
        {
            int b = (x >> i) & 1;
            if(cur -> nxt[b] == NULL) cur -> nxt[b] = new node();
            cur = cur -> nxt[b];
            cur -> sz++;
        }
    }
    void Remove(int x){
        node* cur = root;
        for(int i=B; i>=0; i--)
        {
            int b = (x >> i) & 1;
            cur = cur -> nxt[b];
            cur -> sz--;
        }
    }
    int Maxxor(int x)
    {
        node* cur = root;
        int ans = 0;
        for(int i=B; i>=0; i--)
        {
            int b = !((x >> i) & 1);
            if(cur -> nxt[b] != NULL && cur -> nxt[b] -> sz > 0)
            {
                ans |= (1LL<<i);
                cur = cur -> nxt[b];
            }
            else if(cur -> nxt[!b] != NULL) cur = cur -> nxt[!b];
            else break;
        }
        return ans;
    }
    void del(node* cur) {
    for (int i = 0; i < 2; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
    delete(cur);
  }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
//    srand(time(NULL));


    Trie t;
    t.Insert(0);

    int n;
    cin >> n;
    while(n--)
    {
        char c;
        int x;
        cin >> c >> x;
        if(c == '+') t.Insert(x);
        else if(c == '-') t.Remove(x);
        else cout << t.Maxxor(x) << endl;
    }

    return 0;
}
/// Problem  : https://codeforces.com/contest/706/problem/D
/// Solution : https://codeforces.com/contest/706/submission/163604047

/// Problem : https://cses.fi/problemset/task/1655/ (Max Xor Subarray)

/// Problem : https://codeforces.com/contest/282/problem/E
/// Solution : https://codeforces.com/contest/282/submission/163605232
