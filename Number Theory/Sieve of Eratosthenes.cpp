#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=1e7;
bool check[N];///if true that means not prime otherwise prime
void sieve()
{
    ll i,j;
    check[0]=true;
    check[1]=true;
    for(i=4;i<N;i+=2)check[i]=true;
    for(i=3; i*i<=N; i+=2)
    {
        if(check[i]==false)
        {
            for(j=i*i;j<=N;j+=i)check[j]=true;
        }
    }
}

int main()
{
    ll i,n,temp=0,j;
    sieve();
    while(scanf("%lld",&n)!=EOF)
    {
        cout<< (!check[n]?"Prime":"Not Prime") <<'\n';
    }
    return 0;
}
