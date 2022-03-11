
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

int n;

vector< vector<string> > ans;

bool ok(vector< string > grid,int row,int col)
{
    for(int i=0;i<n;i++)
    {
        if(col!=i && grid[row][i] == 'Q') return false;
        if(row!=i && grid[i][col] == 'Q') return false;
        if(i != row && i-(row-col)>=0 && i-(row-col)<n && grid[i][i-(row-col)]=='Q') return false;
        if(i != row && (row+col)-i>=0 && (row+col)-i<n && grid[i][(row+col)-i]=='Q') return false;
    }
    return true;
}

void go(int row,vector< string > grid)
{
    if(row == n)
    {
        ans.push_back(grid);
        return;
    }
    for(int col=0;col<n;col++)
    {
        if(!ok(grid,row,col)) continue;
        grid[row][col] = 'Q';
        go(row+1,grid);
        grid[row][col] = '.';
    }
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);

    scc(n)

    vector< string > grid(n,string(n,'.'));
    go(0,grid);

    for(vector< string > sol : ans)
    {
        cout<< endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<< sol[i][j] << ' ';
            }
            cout<< endl;
        }
    }

    return 0;
}
