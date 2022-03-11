#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bigmod(ll b,ll p,ll m)
{
    b=b%m;
    if(p==0)
        return 1;
    ll ans=bigmod(b,p/2,m);
    ans=((ans%m)*(ans%m))%m;
    if(p & 1)
        return ((ans%m)*(b%m))%m;
    else
        return ans;

}
int main()
{
    cout<<bigmod(12,10000,122)<<endl;
}
