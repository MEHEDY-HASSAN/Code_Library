#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N = 1e7;
int check[N];///if true that means not prime. otherwise prime
int setbit(int n,int position)/// to change the position'th bit of n to 1
{
    n = n|(1<<position);
    return n;
}
bool checkbit(int n,int position)
{
    return n&(1<<position);
}
void sieve()
{
    ll i,j;

    check[0]=setbit(check[0],0);
    check[0]=setbit(check[0],1);
    for(i=4;i<N;i+=2)check[i>>5]=setbit(check[i>>5],i&31);
    for(i=3; i*i<=N; i+=2)
    {
        if(!checkbit(check[i/32],i&31))/// i/32 is same as i>>5
        {
            for(j=i*i;j<=N;j+=i)check[j>>5]=setbit(check[j/32],j&31);
        }
    }
}
int main()
{
    ll i,n,temp=0,j;
    sieve();
    while(scanf("%lld",&n)!=EOF)
    {
        if(!checkbit(check[n>>5],n&31))
            puts("I am prime ^_^");
        else
            puts("Not prime");
    }
    return 0;
}
