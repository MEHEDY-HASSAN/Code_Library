#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,i,XOR=0,ones=0;
    cin>>n;
    vector<int>v(n);
    for(auto &x:v)
    {
        cin>>x;
        if(x==1)ones++;
        XOR^=x;
    }


    if( ones < n )
    {
        if(XOR==0)
        	puts("Bob");
        else
        	puts("Alice");
    }
    else
    {
        if(XOR==0)
        	puts("Alice");
        else
            puts("Bob");
    }
}
int main()
{
    int _,t=0;
    cin>>_;
    while(++t <= _)
    {
        cout<<"Case "<<t<<": ";
        solve();
    }
}
// Player picking the last stone loses (Variation of Nim Game)
