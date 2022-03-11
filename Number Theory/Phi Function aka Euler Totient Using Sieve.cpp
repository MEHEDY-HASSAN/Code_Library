#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int MAX=2000100;
ll phi[MAX];

/// phi(m) = m(1 - 1/p1)(1 - 1/p2).......
void sievephi()
{
    ll i,j;
    for(i=2;i<MAX;i++)
    {
        if(phi[i]==0)
        {
            phi[i]=i-1;
            for(j=i+i;j<MAX;j+=i)
            {
                if(phi[j]==0)
                {
                    phi[j]=j;
                }
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}

int main()
{
    ll x;
    sievephi();
    /// phi[m] = count of number less than m and co-prime with m
    while(cin>>x)
    {
        cout<<"co-prime with "<<x<<" :"<<phi[x]<<endl;
    }
    return 0;
}
/*
ll po(ll a,ll b)
{
    ll ans=1;
    while(b--) ans*=a;
    return ans;
}
ll prime(ll a)
{
    for(int i=1; i*i<=a; i++)
    {
        if(a%i==0) return 1;
    }
    return 0;
}

void phi(long long int n)
{
    ll i,mul=1,holder,fre=0;
    if(prime(n)==0) mul=n-1;
    else
    {
        for(i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n=n/i;
                    holder=i;
                    fre++;

                }
                mul*=(po(holder,fre-1)*(holder-1));
                fre=0;
            }
        }
        if(n!=1) {

                mul*=(n-1);
        }

    }
    cout << mul << endl;
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    phi(n);
    return 0;
}

*/
