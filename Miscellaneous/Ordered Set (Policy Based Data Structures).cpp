
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
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
// find_by_order() // returns an iterator to the k-th largest element (counting from zero)
// order_of_key() // the number of items in a set that are strictly smaller than our item

typedef tree<
  ll,
  null_type,
  less< ll >,
  rb_tree_tag,
  tree_order_statistics_node_update>ordered_set;

//typedef tree<
//    int,
//    null_type,
//    less<int>,
//    rb_tree_tag,
//    tree_order_statistics_node_update>ordered_set;

//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // works like multiset but be careful
// I can't erase elements with less_equal comparator
// details : https://codeforces.com/blog/entry/11080
int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);


    int n=0,q;
//    scc(q)

    ordered_set X; /// set ; not multiset

    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);


//    cout<<*X.find_by_order(1)<<endl; // 2
//    cout<<*X.find_by_order(2)<<endl; // 4
//    cout<<*X.find_by_order(4)<<endl; // 16
//    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(2)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5


    return 0;
}
