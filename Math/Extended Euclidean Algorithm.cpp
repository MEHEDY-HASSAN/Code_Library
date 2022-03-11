/*
The Euclidean algorithm calculates only the greatest common divisor (GCD) of two integers  and, the extended version also finds a way to represent GCD in terms of a and b, i.e. coefficients x and y for which:
a*x + b*y = GCD(a,b)
*/
#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
typedef long long ll;
using namespace std;

int gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

int main()
{
    /*

    (1/a) mod b = x
    a,b must be co-prime
    so, ax + by = 1 mod b
    ax + by = gcd(a,b)
    here x is the inverse  modulo
    base case 1*x + 0*y = 1

    ax + by = 1
    bx1 + (a mod b)y1 = 1
    bx1 + (a - (a/b)*b )y1 = 1

    x = y1
    y = x1 - (a/b) * y1

    */

    /// find (1/4) mod 7
    /// a=4 , b=7;
    int x,y,a=10,b=10;
    int d = gcd(a,b,x,y);
    cout<< d<< ' ' << x << ' ' << y <<endl;
    x = (x+b)%b; /// since x can be negative
    cout<<"(1/"<<a<<") mod "<<b<<" = "<<x<<endl;

    return 0;
}
